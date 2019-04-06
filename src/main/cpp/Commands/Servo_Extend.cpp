/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Servo_Extend.h"
#include "Robot.h"
#include <iostream>

Servo_Extend::Servo_Extend() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_hatchServo);
}

// Called just before this Command runs the first time
void Servo_Extend::Initialize() {
 
  Robot::m_hatchServo->extend();

}

// Called repeatedly when this Command is scheduled to run
void Servo_Extend::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Servo_Extend::IsFinished() { return false; }

// Called once after isFinished returns true
void Servo_Extend::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Servo_Extend::Interrupted() {}
