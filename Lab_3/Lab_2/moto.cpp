#include "moto.h"

void Moto::initializeEngineProblems() {
    MotoProblem::motoGasProblems.push_back("Exhaust system malfunctions");
    MotoProblem::motoElectricProblems.push_back("Electrical system issues");
    MotoProblem::motoGasolineProblems.push_back("Tire damage or wear");
}
