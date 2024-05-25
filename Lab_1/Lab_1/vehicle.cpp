#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string type;
    string fuelType;
public:
    Vehicle(string t, string fuel) : type(t), fuelType(fuel) {}
    virtual void diagnose() {
        cout << "Diagnostics " << type << " on " << fuelType << endl;
    }
    virtual void repair() = 0;
    virtual void record() = 0;
    virtual void typesOfBreakdowns() = 0;
    virtual bool isBreakdownTypeValid(const string& breakdownType) = 0;
    virtual ~Vehicle() {}
};

#endif 
