#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <string>
#include "di_container.h" 
using namespace std;

class DIContainer;

class Vehicle {
public:
    string name;
    string surname;
    string phone_number;
    vector<string> problems;
    string make;
    string model;
    string engineType;

    Vehicle* next;

    Vehicle(const string& name, const string& surname, const string& phone_number)
        : name(name), surname(surname), phone_number(phone_number), next(nullptr) {}
    virtual ~Vehicle() {}
    virtual bool isTransport() const { return false; }
};

class Transport : public Vehicle {
public:
    string vehicle_name;
    string vehicle_type;
    string engine_type;
    string problem;
    Transport* nextTransport;

    Transport() : Vehicle("", "", ""), vehicle_name(""), vehicle_type(""), engine_type(""), problem(""), nextTransport(nullptr) {}
    virtual bool isTransport() const override { return true; }

    string getVehicleName() const { return vehicle_name; }
    string getVehicleType() const { return vehicle_type; }
    string getEngineType() const { return engine_type; }
    string getProblem() const { return problem; }
};

class VehicleList {
private:
    Vehicle* head;

public:

    Vehicle* getHead() const { return head; }

    virtual void addUser(DIContainer* container);
    virtual void addTransport(DIContainer* container);
    virtual void displayInfo(DIContainer* container);
    virtual void deleteUser(DIContainer* container);
    virtual void deleteTransport(DIContainer* container);
    virtual void deleteTransportBySurname(const std::string& surname, DIContainer* container);
    void setHead(Vehicle* newHead) {
        head = newHead;
    }

    VehicleList();
    ~VehicleList();

};

#endif 
