#include "pch.h"
#include "car.h"

void Car::initializeEngineProblems() {
    CarProblem::carGas.push_back("Engine starting issues");
    CarProblem::carGas.push_back("Brake system malfunctions");
    CarProblem::carGas.push_back("Cooling system issues");
    CarProblem::carElectric.push_back("Electrical system failure");
    CarProblem::carDiezel.push_back("Exhaust system issues");
    CarProblem::carDiezel.push_back("Oil leaks");
    CarProblem::carGasoline.push_back("Engine starting issues");
    CarProblem::carGasoline.push_back("Brake system malfunctions");
    CarProblem::carGasoline.push_back("Cooling system issues");
    CarProblem::carGasoline.push_back("Tire wear or damage");
    CarProblem::carGasoline.push_back("Air conditioning system malfunctions");
    CarProblem::carGasoline.push_back("Clogged filters");
    CarProblem::carGasoline.push_back("Exhaust system issues");
    CarProblem::carGasoline.push_back("Body or glass damage");
}