/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Arduino.h"
#include "RobotMap.h"
#include <iostream>

Arduino::Arduino() : Subsystem("ExampleSubsystem"), arduino(new frc::I2C(frc::I2C::kOnboard, 8))//, recieve(new uint8_t()) 
{
 //uint8_t recieve[12];//12 bytes in which to read the Packet from I2C
}

std::string Arduino::readUint(int num, uint8_t* uint){
  std::string myString = "";
  for (int i = 0; i < num; i++){
    myString += uint[i];
  }

  return myString;
}

void Arduino::readSensors(){
  uint8_t* recieve = new uint8_t(12);
  uint8_t* send = new uint8_t(12);
  /*
  arduino->ReadOnly(11,recieve);
  for (unsigned char i=0;i<11;i++) {
	  std::cout << recieve[i] << "  " << std::endl;
  

  }
*/
  //#if 0
  arduino->Transaction(send, 12, recieve, 12);
  std::string data = readUint(11, recieve);
  std::cout << "Read: " << recieve << std::endl;
  //int x = stoi(data);
  //data.substr(0, index);
  //sscanf(data, "%d", &x);
  /*
  if (printOutputsColorSensors){
    std::cout << "Recieved " <<  stoi(data.substr(0, index)) << ", " <<  stoi(data.substr(index + 1)) << std::endl;
  }
  */
  //#endif
}

void Arduino::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

bool* Arduino::getReadings(){
  return new bool[4];
}

// Put methods for controlling this subsystem
// here. Call these from Commands.4