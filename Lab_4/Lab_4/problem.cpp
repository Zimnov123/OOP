#include "pch.h"
#include "problem.h"

vector<CarProblem> CarProblem::carProblems = {
    CarProblem("Fuel pump failure"),
    CarProblem("Chassis damage or wear")
};

vector<string> CarProblem::carDiezel = {
    "Exhaust system issues",
    "Oil leaks"
};

vector<string> CarProblem::carElectric = {
    "Electrical system failure"
};

vector<string> CarProblem::carGas = {
    "Engine starting issues",
    "Brake system malfunctions",
    "Cooling system issues"
};

vector<string> CarProblem::carGasoline = {
    "Engine starting issues",
    "Brake system malfunctions",
    "Cooling system issues",
    "Tire wear or damage",
    "Air conditioning system malfunctions",
    "Clogged filters",
    "Exhaust system issues",
    "Body or glass damage"
};

vector<TruckProblem> TruckProblem::truckProblems = {
    TruckProblem("Fuel pump failure"),
    TruckProblem("Chassis damage or wear")
};

vector<string> TruckProblem::truckGas = {
    "Transmission problems",
    "Brake system malfunctions",
    "Cooling system issues"
};

vector<string> TruckProblem::truckElectric = {
    "Electrical system failure"
};

vector<string> TruckProblem::truckDiezel = {
    "Exhaust system issues",
    "Oil leaks"
};

vector<string> TruckProblem::truckGasoline = {
    "Engine starting issues",
    "Brake system malfunctions",
    "Cooling system issues",
    "Tire wear or damage",
    "Exhaust system issues",
    "Body or glass damage"
};

vector<MotoProblem> MotoProblem::motoProblems = {
    MotoProblem("Ignition system failure"),
    MotoProblem("Carburetor or intake system issues"),
    MotoProblem("Brake system problems"),
    MotoProblem("Gear shifting difficulties"),
    MotoProblem("Chain damage or wear"),
    MotoProblem("Suspension failure"),
    MotoProblem("Exhaust system malfunctions"),
    MotoProblem("Electrical system issues"),
    MotoProblem("Spark plug malfunction"),
    MotoProblem("Tire damage or wear"),
    MotoProblem("Body or frame damage")
};

vector<string> MotoProblem::motoGasProblems = {
    "Exhaust system malfunctions"
};
vector<string> MotoProblem::motoElectricProblems = {
    "Electrical system issues"
};
vector<string> MotoProblem::motoGasolineProblems = {
    "Tire damage or wear"
};

vector<string> Problem::DefaultProblems = {
    "Transmission problems",
    "Brake failure",
    "Exhaust system problems",
    "Cooling system malfunctions",
    "Electrical system failure",
    "Oil or fuel leaks"
};
