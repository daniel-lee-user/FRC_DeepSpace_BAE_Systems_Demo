/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/DriveTrain.h"
#include "Commands/TankDrive.h"
#include "RobotMap.h"
#include "frc/WPILib.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), 
  left(new phoenix::motorcontrol::can::WPI_TalonSRX(2)), 
  right(new phoenix::motorcontrol::can::WPI_TalonSRX(3)) {
    drive = new DifferentialDrive(*left, *right);
  left->SetInverted(true);
  right->SetInverted(true);
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new TankDrive());
}

void DriveTrain::tankDrive(double leftPow, double rightPow){
  drive->TankDrive(leftPow*0.3, rightPow*0.3, false); 
  // left->Set(ControlMode::PercentOutput, -leftPow);
  // right->Set(ControlMode::PercentOutput, rightPow);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
