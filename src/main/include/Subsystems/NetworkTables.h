/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "RobotMap.h"

class NetworkTables : public frc::Subsystem {
 private:
 
  //nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();
  //std::shared_ptr<nt::NetworkTable> table = inst.GetTable("cv");
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  nt::NetworkTableEntry rectAzimuth; 
  nt::NetworkTableEntry rectDistance;
 public:
  NetworkTables();
  void InitDefaultCommand() override;
  double getAzimuth();
  double getDistance();
};
