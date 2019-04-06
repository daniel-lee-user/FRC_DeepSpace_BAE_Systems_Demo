/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/MoveBucket.h"
#include "Robot.h"

MoveBucket::MoveBucket() {
  Requires(Robot::cargo);
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveBucket::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveBucket::Execute() {
  Robot::cargo->move(-Robot::m_oi->getBucket()->GetY() / 4);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBucket::IsFinished() { return false; }

// Called once after isFinished returns true
void MoveBucket::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBucket::Interrupted() {}
