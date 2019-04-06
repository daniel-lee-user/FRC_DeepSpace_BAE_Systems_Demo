/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/DriverTurn.h"
#include "Robot.h"


DriverTurn::DriverTurn(double power){
  Requires(Robot::m_drive);
  myPow = -power;
}

// Called just before this Command runs the first time
void DriverTurn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriverTurn::Execute() {
  
  Robot::m_drive->tankDrive(myPow, -myPow);
} 

// Make this return true when this Command no longer needs to run execute()
bool DriverTurn::IsFinished() { 
  if (Robot::m_oi->getLeft()->GetTriggerReleased() || Robot::m_oi->getRight()->GetTriggerReleased()){
    return true;
  }
  return false;
}


// Called once after isFinished returns true
void DriverTurn::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriverTurn::Interrupted() {}
