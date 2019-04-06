/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <iostream>
#include <stdio.h>

class Arduino : public frc::Subsystem {
 private:
 frc::I2C* arduino;
 //uint8_t* recieve;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Arduino();
  std::string readUint(int num, uint8_t* uint);
  bool* getReadings();
  void readSensors();
  void InitDefaultCommand() override;
  
};
