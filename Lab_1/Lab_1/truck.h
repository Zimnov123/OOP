#ifndef TRUCK_CPP
#define TRUCK_CPP

#include "vehicle.cpp"

class Truck : public Vehicle {
public:
    Truck(string fuel) : Vehicle("truck", fuel) {}
    void repair() override {
        cout << "Repair of a truck on " << fuelType << " is complete" << endl;
    }
    void record() override {
        cout << "Registration for a truck on " << fuelType << " is complete" << endl;
    }
    void typesOfBreakdowns() override {
        cout << "Types of breakdowns for a truck on " << fuelType << ":" << endl;
        cout << "- Transmission problems" << endl;
        cout << "- Brake failure" << endl;
        cout << "- Frame or body damage" << endl;
        cout << "- Clutch issues" << endl;
        cout << "- Fuel pump failure" << endl;
        cout << "- Exhaust system problems" << endl;
        cout << "- Cooling system malfunctions" << endl;
        cout << "- Chassis damage or wear" << endl;
        cout << "- Electrical system failure" << endl;
        cout << "- Oil or fuel leaks" << endl;
    }
    bool isBreakdownTypeValid(const string& breakdownType) override {
        if (breakdownType == "Transmission problems" || breakdownType == "Brake failure" ||
            breakdownType == "Frame or body damage" || breakdownType == "Clutch issues" ||
            breakdownType == "Fuel pump failure" || breakdownType == "Exhaust system problems" ||
            breakdownType == "Cooling system malfunctions" || breakdownType == "Chassis damage or wear" ||
            breakdownType == "Electrical system failure" || breakdownType == "Oil or fuel leaks") {
            return true;
        }
        return false;
    }
};

#endif 
