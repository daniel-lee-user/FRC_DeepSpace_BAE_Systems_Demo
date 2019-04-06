/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

#include "frc/WPILib.h"
using namespace frc;


class DriveTrain : public frc::Subsystem {
 private:
 phoenix::motorcontrol::can::WPI_TalonSRX* left;
 phoenix::motorcontrol::can::WPI_TalonSRX* right;
 phoenix::motorcontrol::can::WPI_TalonSRX* test;
 DifferentialDrive* drive;
   // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void tankDrive(double leftPow, double rightPow);
  //void moveArm(double armPower);
  void InitDefaultCommand() override;
};
