/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/TimedRobot.h>

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Piston.h"
#include "Subsystems/HatchServo.h"
#include "Subsystems/PressureControl.h"
#include "Subsystems/Arduino.h"
#include "Subsystems/NetworkTables.h"
#include "Subsystems/CargoDoor.h"
#include "AHRS.h"

class Robot : public frc::TimedRobot {
 public:
  static DriveTrain* m_drive;
  static Piston* m_piston;
  static HatchServo* m_hatchServo;
  static PressureControl* m_compressor;
  static cs::UsbCamera camera1;
  static AHRS* navx;
  static Arduino* colorSensors;
  static NetworkTables* cv;
  static CargoDoor* cargo;
  static OI* m_oi;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  // ExampleCommand m_defaultAuto;
  // MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
};

