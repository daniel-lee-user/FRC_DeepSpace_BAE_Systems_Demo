/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/PressureControl.h"
#include "RobotMap.h"
#include <iostream>

PressureControl::PressureControl() : Subsystem("ExampleSubsystem"),
 compressor(new Compressor(COMPRESSOR_PORT)){
  compressor->SetClosedLoopControl(false);
 }

void PressureControl::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PressureControl::compressorOn(){
  //equivalent to starting the PressureControl
  compressor->Start();
  std::cout << "Compressor On --------------------------" << std::endl;
}

void PressureControl::compressorOff(){
  compressor->Stop();
  std::cout << "Compressor Off -------------------------" << std::endl;
}
