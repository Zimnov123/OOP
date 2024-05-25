#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include "problem.h"

class Truck : public Vehicle {
public:
    Truck(const string& make, const string& model, const string& engineType)
        : Vehicle(make, model, engineType) {}

    static void initializeEngineProblems();
};

#endif 
