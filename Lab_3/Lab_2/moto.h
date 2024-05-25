#ifndef MOTO_H
#define MOTO_H

#include "problem.h"
#include "vehicle.h"

class Moto : public Vehicle {
public:
    Moto(const string& make, const string& model, const string& engineType)
        : Vehicle(make, model, engineType) {}

    static void initializeEngineProblems();
};

#endif 
