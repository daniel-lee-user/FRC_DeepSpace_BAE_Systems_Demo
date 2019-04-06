/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/DriveUntilLine.h"
#include "Robot.h"
#include "RobotMap.h"

DriveUntilLine::DriveUntilLine()
 {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_drive);
  Requires(Robot::colorSensors);
}

// Called just before this Command runs the first time
void DriveUntilLine::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void DriveUntilLine::Execute() 
{
  Robot::m_drive->tankDrive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilLine::IsFinished() 
{ 
  
  bool* readings = Robot::colorSensors->getReadings();
  bool sensor1 = readings[0];
  bool sensor2 = readings[1];
  bool sensor3 = readings[2];
  bool sensor4 = readings[3];
   
  if (!sensor1 || !sensor2 || !sensor3 || !sensor4)
  {
    return true;    
  } 
  return false;
}

// Called once after isFinished returns true
void DriveUntilLine::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilLine::Interrupted() {}
