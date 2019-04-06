/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TurnToAngle.h"
#include "Robot.h"
#include <iostream>

TurnToAngle::TurnToAngle(double angle) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_drive);
  myAngle = angle;
  turnConstant = 0.02;
}

// Called just before this Command runs the first time
void TurnToAngle::Initialize() {
  Robot::navx->ZeroYaw();
}

// Called repeatedly when this Command is scheduled to run
void TurnToAngle::Execute() {
  error = myAngle - Robot::navx->GetYaw();
  double power = turnConstant * error;

  std::cout << "Angle: " << Robot::navx->GetYaw() << " Error: " << error << " Power " << power << std::endl;
  if (power > 1){
    power = 0.75;
  }
  else if (power < -1){
    power = -0.75;
  }
  else if (power < 0.1 && power > 0){
    power = 0.1;              
  }
  else if (power > -0.1 && power < 0){
    power = -0.1;
  }
  
  Robot::m_drive->tankDrive(power, -power);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnToAngle::IsFinished() { 

  if (error < 1 && error > -1){
    return true;
  }
  if (!Robot::navx->IsConnected()){
    std::cout << "NavX disconnected error" << std::endl;
    return true;
  }
  
  
  return false;
}

// Called once after isFinished returns true
void TurnToAngle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToAngle::Interrupted() {}
