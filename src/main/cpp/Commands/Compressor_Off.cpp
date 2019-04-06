/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Compressor_Off.h"
#include "Robot.h"

Compressor_Off::Compressor_Off() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_compressor);
}

// Called just before this Command runs the first time
void Compressor_Off::Initialize() {
  Robot::m_compressor->compressorOff();
}

// Called repeatedly when this Command is scheduled to run
void Compressor_Off::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Compressor_Off::IsFinished() { return true; }

// Called once after isFinished returns true
void Compressor_Off::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Compressor_Off::Interrupted() {}
