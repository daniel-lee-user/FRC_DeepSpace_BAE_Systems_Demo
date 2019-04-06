/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/NetworkTables.h"
#include <iostream>

NetworkTables::NetworkTables() : Subsystem("ExampleSubsystem") {
  auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("cv");
  
  inst.StartClient("10.33.41.2");
  inst.StartDSClient();
  //std::cout << "Reading net tables \n";
  
   rectAzimuth = table->GetEntry("rectAzi");
  rectDistance = table->GetEntry("rectDistance");
}

void NetworkTables::InitDefaultCommand() {
  
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double NetworkTables::getAzimuth(){
  
  double azimuth = rectAzimuth.GetDouble(-100);
 
 if (printOutputNetworkTables){
    std::cout << "Azimuth " << azimuth << std::endl;
 }

  return azimuth;
}

double NetworkTables::getDistance(){
  /*
  auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("cv");
  
  inst.StartClient("10.33.41.2");
  inst.StartDSClient();
  //std::cout << "Reading net tables \n";
  
  nt::NetworkTableEntry rectDistance = table->GetEntry("rectDistance");
  */
  double distance = rectDistance.GetDouble(-100);
 
 if (printOutputNetworkTables){
    std::cout << "Distance " << distance << std::endl;
 }

  return distance;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
