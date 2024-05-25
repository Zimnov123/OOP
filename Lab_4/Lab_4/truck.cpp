#include "pch.h"
#include "truck.h"

void Truck::initializeEngineProblems() {
    //gaz
    TruckProblem::truckGas.push_back("Transmission problems");
    TruckProblem::truckGas.push_back("Brake system malfunctions");
    TruckProblem::truckGas.push_back("Cooling system issues");
    //electro
    TruckProblem::truckElectric.push_back("Electrical system failure");
    //diezel
    TruckProblem::truckDiezel.push_back("Oil leaks");
    TruckProblem::truckDiezel.push_back("Exhaust system issues");
    //benzun
    TruckProblem::truckGasoline.push_back("Tire wear or damage");
    TruckProblem::truckGasoline.push_back("Exhaust system issues");
    TruckProblem::truckGasoline.push_back("Body or glass damage");
    TruckProblem::truckGasoline.push_back("Engine starting issues");
    TruckProblem::truckGasoline.push_back("Brake system malfunctions");
    TruckProblem::truckGasoline.push_back("Cooling system issues");
}
