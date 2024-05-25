#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H

#include "vehicle_node.h"
#include <iostream> 

class VehicleList {
private:
    VehicleNode* head;
    int size;

public:
    VehicleList() : head(nullptr), size(0) {}

    VehicleNode* begin() const {
        return head;
    }

    VehicleNode* end() const {
        VehicleNode* temp = head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        return temp;
    }

    void addVehicle(Vehicle* vehicle) {
        VehicleNode* newNode = new VehicleNode(vehicle);
        if (!head) {
            head = newNode;
        }
        else {
            VehicleNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    VehicleNode* find(Vehicle* vehicleToFind) const {
        VehicleNode* temp = head;
        while (temp) {
            if (temp->data == vehicleToFind) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void removeVehicle(Vehicle* vehicle) {
        cout << "Vehicle of type " << vehicle->getType() << " with fuel type " << vehicle->getFuelType() << " has been deleted";
        VehicleNode* current = head;
        VehicleNode* prev = nullptr;

        while (current) {
            if (current->data == vehicle) {
                if (prev)
                    prev->next = current->next;
                else
                    head = current->next;

                delete current->data; 
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void displayVehicles() {
        VehicleNode* temp = head;
        while (temp) {
            cout << "Diagnostics " << temp->data << " on " << temp->data->getFuelType() << endl;
            temp = temp->next;
        }
    }

    void VehicleListClear() {
        VehicleNode* current = head;
        while (current) {
            VehicleNode* next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    ~VehicleList() {
        VehicleListClear();
    }
};

#endif
