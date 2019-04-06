/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/LineFollow.h"
#include "Robot.h"

LineFollow::LineFollow() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_drive);
  Requires(Robot::colorSensors);
}

// Called just before this Command runs the first time
void LineFollow::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LineFollow::Execute() {
  int basePower = 0.1;
  bool sen1 = Robot::colorSensors->getReadings()[0]; // left most
  bool sen2 = Robot::colorSensors->getReadings()[1];
  bool sen3 = Robot::colorSensors->getReadings()[2];
  bool sen4 = Robot::colorSensors->getReadings()[3]; // right most

  int delta = 0.07; // change in power

  if(sen1){ // if the left most sensor is acive, turn left really fast
    Robot::m_drive->tankDrive(basePower - delta, basePower + delta);
  }
  else if(sen4){ // if the right most sensor is acive, turn right really fast
    Robot::m_drive->tankDrive(basePower + delta, basePower - delta);
  }
  else if(sen2 && !sen3){ // otherwise if only the second left sensor is active, turn left slower
    Robot::m_drive->tankDrive(basePower - delta/2, basePower + delta/2);
  }
  else if(sen3 && !sen2){ // otherwise if only the second right sensor is active, turn right slower
    Robot::m_drive->tankDrive(basePower + delta/2, basePower - delta/2);
  }
  else if(sen2 && sen3) { // if both middle sensors are active, drive straight
    Robot::m_drive->tankDrive(basePower, basePower);
  }
}
// Make this return true when this Command no longer needs to run execute()
bool LineFollow::IsFinished() { 
  return(Robot::cv->getDistance() == 24);
}

// Called once after isFinished returns true
void LineFollow::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LineFollow::Interrupted() {}
