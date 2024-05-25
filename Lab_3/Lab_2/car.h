#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include "problem.h"

class Car : public Vehicle {
public:
    Car(const string& make, const string& model, const string& engineType)
        : Vehicle(make, model, engineType) {}

    static void initializeEngineProblems();
};

#endif
