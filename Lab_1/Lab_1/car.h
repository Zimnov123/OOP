#ifndef CAR_CPP
#define CAR_CPP

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car(string fuel) : Vehicle("car", fuel) {}
    void repair() override {
        cout << "Car repair on " << fuelType << " is complete" << endl;
    }
    void record() override {
        cout << "Registration for a passenger car on " << fuelType << " is complete" << endl;;
    }
    void typesOfBreakdowns() override {
        cout << "Types of breakdowns for a passenger car on " << fuelType << ":" << endl;
        cout << "- Engine starting issues" << endl;
        cout << "- Transmission problems" << endl;
        cout << "- Brake system malfunctions" << endl;
        cout << "- Oil leaks" << endl;
        cout << "- Cooling system issues" << endl;
        cout << "- Electrical system failure" << endl;
        cout << "- Suspension problems" << endl;
        cout << "- Tire wear or damage" << endl;
        cout << "- Air conditioning system malfunctions" << endl;
        cout << "- Clogged filters" << endl;
        cout << "- Exhaust system issues" << endl;
        cout << "- Body or glass damage" << endl;
    }
    bool isBreakdownTypeValid(const string& breakdownType) override {
        if (breakdownType == "Engine starting issues" || breakdownType == "Transmission problems" ||
            breakdownType == "Brake system malfunctions" || breakdownType == "Oil leaks" ||
            breakdownType == "Cooling system issues" || breakdownType == "Electrical system failure" ||
            breakdownType == "Suspension problems" || breakdownType == "Tire wear or damage" ||
            breakdownType == "Air conditioning system malfunctions" || breakdownType == "Clogged filters" ||
            breakdownType == "Exhaust system issues" || breakdownType == "Body or glass damage") {
            return true;
        }
        return false;
    }
};

#endif 
