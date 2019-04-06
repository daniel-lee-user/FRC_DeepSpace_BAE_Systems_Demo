#pragma once
#include "OI.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include <frc/commands/Subsystem.h>

class CargoDoor : public frc::Subsystem {
private:
	TalonSRX* cargoDoorMotor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
 	CargoDoor();
	~CargoDoor();
	void move(double cargoValue);
	TalonSRX* getCargoMotor();
	void reset();
	double getPosition();
	void InitDefaultCommand() override;
};