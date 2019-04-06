#ifndef Piston_Retract_H
#define Piston_Retract_H

#include <frc/commands/Command.h>
#include "frc/WPILib.h"

class Piston_Retract : public frc::Command {
public:
	Piston_Retract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Piston_Retract_H
