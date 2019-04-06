#include "Subsystems/Piston.h"
#include "RobotMap.h"
#include <iostream>
#include "Commands/Piston_Retract.h"

Piston::Piston() : Subsystem("Piston"), piston(new DoubleSolenoid(PCM_TALON_ID, PISTON_FORWARD_CHANNEL, PISTON_REVERSE_CHANNEL)) {
}

void Piston::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Piston_Retract());
}

void Piston::extend(){
	piston->Set(frc::DoubleSolenoid::Value::kForward);
}
void Piston::retract(){
	piston->Set(frc::DoubleSolenoid::Value::kReverse);
}
void Piston::solenoidOff(){
	piston->Set(frc::DoubleSolenoid::Value::kOff);
}
