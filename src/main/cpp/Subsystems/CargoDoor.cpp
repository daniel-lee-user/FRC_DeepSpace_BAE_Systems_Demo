/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/CargoDoor.h"
#include "frc/WPILib.h"
#include "iostream"
#include "Commands/MoveBucket.h"

CargoDoor::CargoDoor() : Subsystem("CargoDoor"), cargoDoorMotor(new TalonSRX(cargoMotorPort))
{
	//armEncoder->Reset();
cargoDoorMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 10);
	// left->ConfigEncoderCodesPerRev(360);
cargoDoorMotor->SetSelectedSensorPosition(0, 0, 10);
	std::cout << "cargoDoorMotor" << std::endl;
cargoDoorMotor->SetInverted(false);
}

void CargoDoor::InitDefaultCommand()
{
	SetDefaultCommand(new MoveBucket());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void CargoDoor::move(double cargoValue)
{
cargoDoorMotor->Set(ControlMode::PercentOutput, cargoValue*0.5);
}

CargoDoor::~CargoDoor()
{
	if (cargoDoorMotor != nullptr)
	{
		delete cargoDoorMotor;
		cargoDoorMotor = nullptr;
	}
}

void CargoDoor::reset()
{
	//std::cout << "hey" << std::endl;
cargoDoorMotor->SetSelectedSensorPosition(0);
}

double CargoDoor::getPosition()
{
	//std::cout << "hi" << std::endl;
	return cargoDoorMotor->GetSelectedSensorPosition(0);
	//std::cout << "hi 2" << std::endl;
}
TalonSRX* CargoDoor::getCargoMotor()
{
	return cargoDoorMotor;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.