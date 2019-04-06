#include "Commands/MoveCargoDoor.h"
#include "iostream"
using namespace std;

MoveCargoDoor::MoveCargoDoor(double setpoint) {
  Requires(Robot::cargo);
  std::cout << "constructor" << std::endl;
  //Robot::cargo->reset();
  mysetpoint = setpoint;
   // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveCargoDoor::Initialize() {
  
  std::cout << "initialize1" << std::endl;
  std::cout << "initialize2" << std::endl;
  input = (int)mysetpoint * (4096/360);
  if (Robot::cargo->getPosition() > input) {
   // target = Robot::cargo->getPosition() + input;
    direction = -1;
  }
  else if (Robot::cargo->getPosition() < input) {
//target = Robot::cargo->getPosition() - input;
    direction = 1;
  }
//  std::cout << target << std::endl;

  
}

// Called repeatedly when this Command is scheduled to run
void MoveCargoDoor::Execute() {
  currentPosition = Robot::cargo->getPosition();
  cout << "Current Position:" << currentPosition << endl;
  cout << "diff:" << fabs (input - currentPosition) << endl;
  Robot::cargo->move(direction * 0.15);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCargoDoor::IsFinished() {
   if (direction < 0 && (input - currentPosition > 0
   //|| Robot::cargo->getCargoMotor()->GetSensorCollection().IsFwdLimitSwitchClosed())
   || Robot::cargo->getCargoMotor()->GetSensorCollection().IsRevLimitSwitchClosed())) 
  { //|| Robot::cargo->getCargoPort()->GetSensorCollection().IsFwdLimitSwitchClosed())   {
     return true;
   }
   else if (direction > 0 && (input - currentPosition < 0
  || Robot::cargo->getCargoMotor()->GetSensorCollection().IsFwdLimitSwitchClosed())){
   //|| Robot::cargo->getCargoMotor()->GetSensorCollection().IsRevLimitSwitchClosed()) {
     return true;
   }
   else {
     return false;
   }
  }

// Called once after isFinished returns true
void MoveCargoDoor::End() {
Robot::cargo->move(0);
std::cout << "Finished" << std::endl;
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCargoDoor::Interrupted() {}