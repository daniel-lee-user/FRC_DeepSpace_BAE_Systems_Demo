#ifndef Piston_Extend_H
#define Piston_Extend_H

#include <frc/commands/Command.h>
#include "frc/WPILib.h"

class Piston_Extend : public frc::Command {
public:
	Piston_Extend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Extend_H
