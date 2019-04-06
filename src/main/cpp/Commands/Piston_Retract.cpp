#include "Commands/Piston_Retract.h"
#include "Robot.h"

Piston_Retract::Piston_Retract() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::m_piston);
}

// Called just before this Command runs the first time
void Piston_Retract::Initialize() {
	Robot::m_piston->retract();
}

// Called repeatedly when this Command is scheduled to run
void Piston_Retract::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Piston_Retract::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void Piston_Retract::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Piston_Retract::Interrupted() {

}
