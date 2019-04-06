#ifndef Piston_Off_H
#define Piston_Off_H

#include <frc/commands/Command.h>
#include "frc/WPILib.h"

class Piston_Off : public frc::Command {
public:
	Piston_Off();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Off_H
