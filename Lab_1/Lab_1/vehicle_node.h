#ifndef VEHICLE_NODE_H
#define VEHICLE_NODE_H

#include "vehicle.h"

class VehicleNode {
private:
    Vehicle* vehicle;

public:
    Vehicle* data;
    VehicleNode* next;

    VehicleNode(Vehicle* v) : vehicle(v) {}

    Vehicle* getVehicle() const {
        return vehicle;
    }
};

#endif
