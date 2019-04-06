#include <QTRSensors.h>
#include <Wire.h>

// This example is designed for use with eight QTR-1RC sensors or the 
eight sensors of a
// QTR-8RC module.  These reflectance sensors should be connected to 
digital inputs 3 to 10.
// The QTR-8RC's emitter control pin (LEDON) can optionally be connected 
to digital pin 2,
// or you can leave it disconnected and change the EMITTER_PIN #define 
below from 2 to
// QTR_NO_EMITTER_PIN.

// The setup phase of this example calibrates the sensor for ten seconds 
and turns on
// the LED built in to the Arduino on pin 13 while calibration is going 
on.
// During this phase, you should expose each reflectance sensor to the 
lightest and
// darkest readings they will encounter.
// For example, if you are making a line follower, you should slide the 
sensors across the
// line during the calibration phase so that each sensor can get a 
reading of how dark the
// line is and how light the ground is.  Improper calibration will 
result in poor readings.
// If you want to skip the calibration phase, you can get the raw sensor 
readings
// (pulse times from 0 to 2500 us) by calling qtrrc.read(sensorValues) 
instead of
// qtrrc.readLine(sensorValues).

// The main loop of the example reads the calibrated sensor values and 
uses them to
// estimate the position of a line.  You can test this by taping a piece 
of 3/4" black
// electrical tape to a piece of white paper and sliding the sensor 
across it.  It
// prints the sensor values to the serial monitor as numbers from 0 
(maximum reflectance)
// to 1000 (minimum reflectance) followed by the estimated location of 
the line as a number
// from 0 to 5000.  1000 means the line is directly under sensor 1, 2000 
means directly
// under sensor 2, etc.  0 means the line is directly under sensor 0 or 
was last seen by
// sensor 0 before being lost.  5000 means the line is directly under 
sensor 5 or was
// last seen by sensor 5 before being lost.


#define NUM_SENSORS   4     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor 
outputs to go low
#define EMITTER_PIN   14     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, 
respectively
QTRSensorsRC qtrrc((unsigned char[]) {4,5,6,7},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

//ABH: Define new variable that gets read by the ISR
//to send to RoboRio
//We will send:
//     2 bytes for every sensor 
//     1 byte for the Sequence number, which will be incremented just to ensure that
//            On the Roborio, we can confirm that we are getting all the data
//            Sent by Adrunio. This will rollover after every 255.
//     2 byte (last 2 bytes) set to 0xAA and 0xBB. This is constant that will help us determine 
//            the endian-ness on the RoboRio end.
//
// Total 11 bytes (Assuming 4 sensors)
volatile char sensorValsForRobo[2*NUM_SENSORS+3];

unsigned int pos;

void setup()
{

  sensorValsForRobo[2*NUM_SENSORS+1] = 0xAA; //Hardcoded last byte
  sensorValsForRobo[2*NUM_SENSORS+2] = 0xBB; //Hardcoded last byte

  Wire.begin(8);                // join i2c bus with address #8
  //Wire.onReceive(receiveData); // register incoming data
  Wire.onRequest(sendData); //register a request for data
  Serial.begin(9600);
  
  //delay(500);
  pinMode(13, OUTPUT);      
  digitalWrite(13, HIGH);  // turn on Arduino's LED to indicate we are 
in calibration mode
  Serial.write("start");
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 
seconds
  {
    //qtrrc.calibrate();       // reads all sensors 10 times at 2500 us 
per read (i.e. ~25 ms per call)
  }
  Serial.write("end");
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we 
are through with calibration

  // print the calibration minimum values measured when emitters were on
 
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  //delay(1000);
}


void loop()
{
  // read calibrated sensor values and obtain a measure of the line 
position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = 
qtrrc.readLine(sensorValues);
  pos = qtrrc.readLine(sensorValues);
  qtrrc.read(sensorValues);

  //Package the data for the RoboRio
  noInterrupts(); //Lock the interrupt, so that the sendData function
                  //Does not read something that is half prepared.
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    sensorValsForRobo[2*i] = (unsigned char) (sensorValues[i] & 0xFF);
    sensorValsForRobo[2*i+1] = (unsigned char)((sensorValues[i] >> 8) & 0xFF);
  }
  interrupts(); //Unlock Interrupts

  // print the sensor values as numbers from 0 to 1000, where 0 means 
maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    if(sensorValues[i]<500){
      Serial.write("White");
    }
    else{
      Serial.write("Black");
    }
    //Serial.print(sensorValues[i]);
    Serial.print('\t');
  }

  Serial.print('\n');
  
  //Serial.println(); // uncomment this line if you are using raw values
  //Serial.println(position); // comment this line out if you are using 
raw values

  //Sdelay(250);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveData()
{
   while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
   }
Serial.println("");
}

// function that executes whenever data is requested from master
// this function is registered as an event, see setup()
/*String createCharArray(char[] array1, char[] array2){
  char totalData[sizeof(array1) + sizeof(array2)]; 

  for (int i = 0; i < sizeof(array1); i++){
    totalData[i] = array1[i];
  }
  for (int i = sizeof(array1) + 1; i < sizeof(array1) + sizeof(array2); 
i++){
    totalData[1] = array2[i - sizeof(array1)];
  }

  return (String)totalData;
}*/

char* arrayCombiner(char array1[4], char array2[4])
{
  char dest[24];
  

  strcpy(dest, array1);
  strcat(dest, ";");
  strcat(dest, array2);

  return dest;
}

void sendData()
{
  static unsigned char robo_pkt_seq_no = 0;
  sensorValsForRobo[2*NUM_SENSORS] = robo_pkt_seq_no;
  robo_pkt_seq_no++;
  Wire.write(sensorValsForRobo,sizeof(sensorValsForRobo));

#if 0
  //char data = 10;
   //if(sensorValues[0]<500){
    //Wire.write(data);

    //data = 5;
   //if(sensorValues[0]<500){
    float sensorReading = sensorValues[0];
    char sensorValue1[4];
    dtostrf(sensorReading, 4, 0, sensorValue1);

    sensorReading = sensorValues[1];
    char sensorValue2[4];
    dtostrf(sensorReading, 4, 0, sensorValue2);

    sensorReading = sensorValues[2];
    char sensorValue3[4];
    dtostrf(sensorReading, 4, 0, sensorValue3);

    sensorReading = sensorValues[3];
    char sensorValue4[4];
    dtostrf(sensorReading, 4, 0, sensorValue4);

    //data = data + " " + pos;
    //char mything1[6] = "Hello";
    //char mything2[6] = "World";
    //Wire.write(arrayCombiner(mything1, mything2));
    Wire.write(arrayCombiner(arrayCombiner(sensorValue1, sensorValue2), 
arrayCombiner(sensorValue3, sensorValue4)));
    //Wire.write(func(func(sensorValue1, sensorValue2), 
func(sensorValue3, sensorValue4)));
    //Wire.write("" + sensorValues[0] + " " + sensorValues[1] + " "  + 
sensorValues[2] + " "  + sensorValues[3]);
    
    //Wire.write("Hello World");
    //Wire.print(true);
   //}
#endif   
}
