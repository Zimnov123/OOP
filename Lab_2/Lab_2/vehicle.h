#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <string>
using namespace std;

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
};

class Transport : public Vehicle {
public:
    string vehicle_name;
    string vehicle_type;
    string engine_type;
    string problem;
    Transport() : Vehicle("", "", ""), vehicle_name(""), vehicle_type(""), engine_type(""), problem("") {}
};

class VehicleList {
private:
    Vehicle* head;

public:

    virtual void addUser();

    virtual void addTransport();

    virtual void displayInfo();

    virtual void deleteTransport(const string& vehicle_name);

    virtual void deleteTransportOrUser();

    virtual void deleteUser(const string& surname);

    VehicleList();
    ~VehicleList();

};

#endif 