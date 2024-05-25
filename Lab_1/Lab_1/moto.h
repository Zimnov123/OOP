#ifndef MOTO_CPP
#define MOTO_CPP

#include "vehicle.cpp"

class Moto : public Vehicle {
public:
    Moto(string fuel) : Vehicle("motorcycle", fuel) {}
    void repair() override {
        cout << "Motorcycle repair on " << fuelType << " is complete" << endl;
    }
    void record() override {
        cout << "Registration for a motorcycle on " << fuelType << " is complete" << endl;
    }
    void typesOfBreakdowns() override {
        cout << "Types of breakdowns for a motorcycle on " << fuelType << ":" << endl;
        cout << "- Ignition system failure" << endl;
        cout << "- Carburetor or intake system issues" << endl;
        cout << "- Brake system problems" << endl;
        cout << "- Gear shifting difficulties" << endl;
        cout << "- Chain damage or wear" << endl;
        cout << "- Suspension failure" << endl;
        cout << "- Exhaust system malfunctions" << endl;
        cout << "- Electrical system issues" << endl;
        cout << "- Spark plug malfunction" << endl;
        cout << "- Tire damage or wear" << endl;
        cout << "- Body or frame damage" << endl;
    }
    bool isBreakdownTypeValid(const string& breakdownType) override {
        if (breakdownType == "Ignition system failure" || breakdownType == "Carburetor or intake system issues" ||
            breakdownType == "Brake system problems" || breakdownType == "Gear shifting difficulties" ||
            breakdownType == "Chain damage or wear" || breakdownType == "Suspension failure" ||
            breakdownType == "Exhaust system malfunctions" || breakdownType == "Electrical system issues" ||
            breakdownType == "Spark plug malfunction" || breakdownType == "Tire damage or wear" ||
            breakdownType == "Body or frame damage") {
            return true;
        }
        return false;
    }
};

#endif 
