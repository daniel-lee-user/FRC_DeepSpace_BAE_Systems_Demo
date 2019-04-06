/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Servo_Retract.h"
#include "Robot.h"

#include <iostream>

Servo_Retract::Servo_Retract() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_hatchServo);
}

// Called just before this Command runs the first time
void Servo_Retract::Initialize() {

  Robot::m_hatchServo->retract();
  //std::cout << "dsiuadsahduihasiudhasid" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void Servo_Retract::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Servo_Retract::IsFinished() { return false; }

// Called once after isFinished returns true
void Servo_Retract::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Servo_Retract::Interrupted() {}
