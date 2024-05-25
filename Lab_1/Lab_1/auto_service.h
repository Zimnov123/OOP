#ifndef AUTO_SERVICE_CPP
#define AUTO_SERVICE_CPP

#include "vehicle_list.h"
#include "vehicle.h"
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class RepairInfo {
public:
    pair<int, string> info;
    vector<Vehicle*> vehicles;

    RepairInfo() : info(make_pair(0, "")) {}

    RepairInfo(pair<int, string> i, vector<Vehicle*> v) : info(i), vehicles(v) {}
};

class AutoService {
private:
    static const int MAX_VEHICLES = 100;
    VehicleList vehicles;
    int numVehicles;
    unordered_map<string, RepairInfo> repairInfo;

public:
    AutoService() : numVehicles(0) {
        initializeRepairInfo();
    }

    void serviceVehicles() {
        for (auto& vehicleNode : vehicles) {
            Vehicle* currentVehicle = vehicleNode.data;
            cout << "Diagnosing and repairing vehicle of type " << currentVehicle->getType() << " with fuel type " << currentVehicle->getFuelType() << " was complete" << endl;
            currentVehicle->diagnose();
            currentVehicle->repair();
        }
    }

    void displayRepairInfo(const string& breakdown) {
        auto it = repairInfo.find(breakdown);
        if (it != repairInfo.end()) {
            cout << "Time required: " << it->second.info.first << " hours" << endl;
            cout << "Tools required: " << it->second.info.second << endl;
        }
        else {
            cout << "Repair information not available for the specified breakdown." << endl;
        }
    }

    void addVehicle(Vehicle* v) {
        vehicles.addVehicle(v);
        cout << "Vehicle of type " << v->getType() << " with fuel type " << v->getFuelType() << " has been added" << endl;
    }

    void registerRepair(Vehicle* vehicle, const string& repairType, const string& breakdownType) {
        auto it = repairInfo.find(breakdownType);
        if (it != repairInfo.end()) {
            it->second.vehicles.push_back(vehicle);
            cout << "Added repair for breakdown type: " << breakdownType << endl;
        }
        else {
            RepairInfo newRepairInfo(make_pair(1, repairType), { vehicle });
            repairInfo[breakdownType] = newRepairInfo;
            cout << "Added new breakdown type: " << breakdownType << endl;
        }
    }

    void addRepairInfoForVehicle(Vehicle& vehicle, const string& breakdownType) {
        if (vehicle.isBreakdownTypeValid(breakdownType)) {
            auto repairDetails = repairInfo.find(breakdownType);
            if (repairDetails != repairInfo.end()) {
                repairDetails->second;
                cout << "Repair information added for " << breakdownType << " for the vehicle." << endl;
            }
            else {
                cout << "Repair information not available for " << breakdownType << "." << endl;
            }
        }
        else {
            cout << "Cannot add repair information. Invalid breakdown type for the vehicle." << endl;
        }
    }

    void initializeRepairInfo() {
        vector<Vehicle*> vehicles;

        RepairInfo repairInfoEntry1(make_pair(1, "Wrench set, multimeter"), vehicles);
        repairInfo["Engine starting issues"] = repairInfoEntry1;

        RepairInfo repairInfoEntry2(make_pair(4, "Transmission jack, socket set"), vehicles);
        repairInfo["Transmission problems"] = repairInfoEntry2;

        RepairInfo repairInfoEntry3(make_pair(2, "Brake bleeder kit, socket set"), vehicles);
        repairInfo["Brake system malfunctions"] = repairInfoEntry3;

        RepairInfo repairInfoEntry4(make_pair(1, "Oil filter wrench, drain pan"), vehicles);
        repairInfo["Oil leaks"] = repairInfoEntry4;

        RepairInfo repairInfoEntry5(make_pair(3, "Coolant pressure tester, hose clamp pliers"), vehicles);
        repairInfo["Cooling system issues"] = repairInfoEntry5;

        RepairInfo repairInfoEntry6(make_pair(3, "Diagnostic scanner, wire strippers"), vehicles);
        repairInfo["Electrical system failure"] = repairInfoEntry6;

        RepairInfo repairInfoEntry7(make_pair(4, "Jack stands, ball joint separator"), vehicles);
        repairInfo["Suspension problems"] = repairInfoEntry7;

        RepairInfo repairInfoEntry8(make_pair(1, "Tire iron, air compressor"), vehicles);
        repairInfo["Tire wear or damage"] = repairInfoEntry8;

        RepairInfo repairInfoEntry9(make_pair(4, "Refrigerant gauge set, vacuum pump"), vehicles);
        repairInfo["Air conditioning system malfunctions"] = repairInfoEntry9;

        RepairInfo repairInfoEntry10(make_pair(1, "Screwdriver set, filter wrench"), vehicles);
        repairInfo["Clogged filters"] = repairInfoEntry10;

        RepairInfo repairInfoEntry11(make_pair(2, "Exhaust pipe cutter, welding torch"), vehicles);
        repairInfo["Exhaust system issues"] = repairInfoEntry11;

        RepairInfo repairInfoEntry12(make_pair(0, "Body filler, windshield installation kit"), vehicles);
        repairInfo["Body or glass damage"] = repairInfoEntry12;

        RepairInfo repairInfoEntry13(make_pair(3, "Diesel fuel pressure tester, flare nut wrench set"), vehicles);
        repairInfo["Diesel fuel system problems"] = repairInfoEntry13;

        RepairInfo repairInfoEntry14(make_pair(1, "Glow plug socket set, ratchet wrench"), vehicles);
        repairInfo["Glow plug issues"] = repairInfoEntry14;

        RepairInfo repairInfoEntry15(make_pair(4, "DPF cleaning kit, wrench set"), vehicles);
        repairInfo["Diesel particulate filter (DPF) filter problems"] = repairInfoEntry15;

        RepairInfo repairInfoEntry16(make_pair(2, "Fuel line disconnect tool, hose clamp pliers"), vehicles);
        repairInfo["Fuel leakage"] = repairInfoEntry16;

        RepairInfo repairInfoEntry17(make_pair(2, "Coolant flush kit, hose clamp pliers"), vehicles);
        repairInfo["Heating system malfunctions"] = repairInfoEntry17;

        RepairInfo repairInfoEntry18(make_pair(1, "Battery terminal cleaner, voltmeter"), vehicles);
        repairInfo["Battery issues"] = repairInfoEntry18;

        RepairInfo repairInfoEntry19(make_pair(2, "Alternator test bench, wrench set"), vehicles);
        repairInfo["Charging system malfunctions"] = repairInfoEntry19;

        RepairInfo repairInfoEntry20(make_pair(3, "Motor insulation tester, wire crimpers"), vehicles);
        repairInfo["Electric motor problems"] = repairInfoEntry20;

        RepairInfo repairInfoEntry21(make_pair(2, "OBD-II scanner, laptop"), vehicles);
        repairInfo["Software control issues"] = repairInfoEntry21;

        RepairInfo repairInfoEntry22(make_pair(4, "Diagnostic software, wiring diagram"), vehicles);
        repairInfo["Electronic management system failure"] = repairInfoEntry22;

        RepairInfo repairInfoEntry23(make_pair(4, "Transmission jack, socket set"), vehicles);
        repairInfo["Transmission problems (Truck)"] = repairInfoEntry23;

        RepairInfo repairInfoEntry24(make_pair(3, "Brake drum puller, brake caliper tool set"), vehicles);
        repairInfo["Brake failure (Truck)"] = repairInfoEntry24;

        RepairInfo repairInfoEntry25(make_pair(0, "Frame straightening equipment, welding machine"), vehicles);
        repairInfo["Frame or body damage (Truck)"] = repairInfoEntry25;

        RepairInfo repairInfoEntry26(make_pair(2, "Clutch alignment tool, socket set"), vehicles);
        repairInfo["Clutch issues (Truck)"] = repairInfoEntry26;

        RepairInfo repairInfoEntry27(make_pair(3, "Fuel pressure gauge, flare nut wrench set"), vehicles);
        repairInfo["Fuel pump failure (Truck)"] = repairInfoEntry27;

        RepairInfo repairInfoEntry28(make_pair(4, "Hydraulic jack, wrench set"), vehicles);
        repairInfo["Lift system malfunctions (Truck)"] = repairInfoEntry28;

        RepairInfo repairInfoEntry29(make_pair(3, "Pneumatic pressure gauge, air compressor"), vehicles);
        repairInfo["Pneumatic system issues (Truck)"] = repairInfoEntry29;

        RepairInfo repairInfoEntry30(make_pair(2, "Exhaust pipe expander, welding torch"), vehicles);
        repairInfo["Exhaust system problems (Truck)"] = repairInfoEntry30;

        RepairInfo repairInfoEntry31(make_pair(2, "Coolant pressure tester, hose clamp pliers"), vehicles);
        repairInfo["Cooling system malfunctions (Truck)"] = repairInfoEntry31;

        RepairInfo repairInfoEntry32(make_pair(0, "Chassis inspection tools, welding machine"), vehicles);
        repairInfo["Chassis damage or wear (Truck)"] = repairInfoEntry32;

        RepairInfo repairInfoEntry33(make_pair(3, "Multimeter, wire strippers"), vehicles);
        repairInfo["Electrical system failure (Truck)"] = repairInfoEntry33;

        RepairInfo repairInfoEntry34(make_pair(2, "Oil filter wrench, drain pan"), vehicles);
        repairInfo["Oil or fuel leaks (Truck)"] = repairInfoEntry34;

        RepairInfo repairInfoEntry35(make_pair(2, "Spark plug wrench, ignition timing light"), vehicles);
        repairInfo["Ignition system failure (Motorcycle)"] = repairInfoEntry35;

        RepairInfo repairInfoEntry36(make_pair(2, "Carburetor synchronization tool, socket set"), vehicles);
        repairInfo["Carburetor or intake system issues (Motorcycle)"] = repairInfoEntry36;

        RepairInfo repairInfoEntry37(make_pair(1, "Brake bleeding kit, brake piston compressor"), vehicles);
        repairInfo["Brake system problems (Motorcycle)"] = repairInfoEntry37;

        RepairInfo repairInfoEntry38(make_pair(2, "Gear shifter adjustment tool, socket set"), vehicles);
        repairInfo["Gear shifting difficulties (Motorcycle)"] = repairInfoEntry38;

        RepairInfo repairInfoEntry39(make_pair(1, "Chain breaker tool, chain lubricant"), vehicles);
        repairInfo["Chain damage or wear (Motorcycle)"] = repairInfoEntry39;

        RepairInfo repairInfoEntry40(make_pair(2, "Motorcycle lift, suspension spanner wrench"), vehicles);
        repairInfo["Suspension problems"] = repairInfoEntry40;

        RepairInfo repairInfoEntry41(make_pair(1, "Exhaust pipe cutter, welding torch"), vehicles);
        repairInfo["Exhaust system issues"] = repairInfoEntry41;

        RepairInfo repairInfoEntry42(make_pair(2, "Multimeter, wire crimpers"), vehicles);
        repairInfo["Electrical system issues"] = repairInfoEntry42;

        RepairInfo repairInfoEntry43(make_pair(1, "Spark plug socket, spark plug gap tool"), vehicles);
        repairInfo["Spark plug malfunction"] = repairInfoEntry43;

        RepairInfo repairInfoEntry44(make_pair(1, "Tire irons, tire pressure gauge"), vehicles);
        repairInfo["Tire damage or wear"] = repairInfoEntry44;

        RepairInfo repairInfoEntry45(make_pair(0, "Bodywork repair tools, welding machine"), vehicles);
        repairInfo["Body or frame damage"] = repairInfoEntry45;

        RepairInfo repairInfoEntry46(make_pair(2, "Coolant flush kit, hose clamp pliers"), vehicles);
        repairInfo["Cooling system problems"] = repairInfoEntry46;

    }

    ~AutoService() {
        vehicles.VehicleListClear();
    }
};

#endif
