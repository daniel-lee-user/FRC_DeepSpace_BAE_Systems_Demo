#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class MoveCargoDoor : public frc::Command {
 private:
 double direction;
 double input;
 int target;
 double currentPosition;
 double mysetpoint;
 public:
  MoveCargoDoor(double setpoint);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};