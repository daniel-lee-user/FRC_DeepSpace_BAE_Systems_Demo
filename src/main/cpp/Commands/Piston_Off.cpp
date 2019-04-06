#include "Commands/Piston_Off.h"
#include "Robot.h"

Piston_Off::Piston_Off() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::m_piston);
}

// Called just before this Command runs the first time
void Piston_Off::Initialize() {
	Robot::m_piston->solenoidOff();
}

// Called repeatedly when this Command is scheduled to run
void Piston_Off::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Piston_Off::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void Piston_Off::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Piston_Off::Interrupted() {

}
