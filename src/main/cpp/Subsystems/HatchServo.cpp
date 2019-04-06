/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/HatchServo.h"
#include "RobotMap.h"
#include <iostream>
#include "Commands/Servo_Retract.h"

HatchServo::HatchServo() : Subsystem("ExampleSubsystem"), servo(new Servo(SERVO_PORT)){}

void HatchServo::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new Servo_Retract());
}

void HatchServo::extend(){
  servo->Set(0);
}

void HatchServo::retract(){
  servo->Set(3);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
