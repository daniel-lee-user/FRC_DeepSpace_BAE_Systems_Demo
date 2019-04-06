/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPILib.h"
using namespace frc;

class OI {
  private:
    Joystick* leftJoy;
    Joystick* rightJoy;
    
    Joystick*cargoStick;
    Button* pistonExtendButton;
    Button* pistonRetractButton;
    
    Button* pistonOffButton;

    Button* compressorOnButton;
    Button* compressorOffButton;

    Button* servoExtendButton;
    Button* servoRetractButton;
    Button* rDriveTurn;
    Button* lDriveTurn;
    
  public:
  Joystick* getLeft();
  Joystick* getRight();
  Joystick* getBucket();
  OI();
};
