/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/ResetEncoder.h"
#include "Robot.h"
ResetEncoder::ResetEncoder() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::cargo);
}

// Called just before this Command runs the first time
void ResetEncoder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ResetEncoder::Execute() {
  Robot::cargo->reset();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetEncoder::IsFinished() { return true; }

// Called once after isFinished returns true
void ResetEncoder::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetEncoder::Interrupted() {}
