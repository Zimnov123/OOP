#include "vehicle.h"
#include "problem.h"
#include <iostream>

VehicleList::VehicleList() : head(nullptr) {}

VehicleList::~VehicleList() {
    while (head != nullptr) {
        Vehicle* temp = head;
        head = head->next;
        delete temp;
    }
}

string chooseProblems(string vehicle_type, string engine_type);

void VehicleList::addUser() {
    string surname;
    cout << "Enter your surname: ";
    cin >> surname;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    string phone_number;
    cout << "Enter your phone number: ";
    cin >> phone_number;
    cout << endl;
    Vehicle* newUser = new Vehicle(name, surname, phone_number);
    newUser->name = name;
    newUser->surname = surname;
    newUser->phone_number = phone_number;
    newUser->next = head;
    head = newUser;
}

string chooseVehicleType() {
    cout << "1. Car\n";
    cout << "2. Truck\n";
    cout << "3. Motorcycle\n";
    cout << "Choose vehicle type: ";
    int choice;
    cin >> choice;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string vehicle_type;
    switch (choice) {
    case 1:
        vehicle_type = "Car";
        break;
    case 2:
        vehicle_type = "Truck";
        break;
    case 3:
        vehicle_type = "Motorcycle";
        break;
    default:
        cout << "Invalid choice. Setting vehicle type to Car by default.\n";
        vehicle_type = "Car";
    }
    return vehicle_type;
}

string chooseEngineType() {
    cout << "1. Gas\n";
    cout << "2. Electric\n";
    cout << "3. Diezel\n";
    cout << "4. Gazoline\n";
    cout << "Choose engine type: ";
    int choice;
    cin >> choice;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string engine_type;
    switch (choice) {
    case 1:
        engine_type = "Gas";
        break;
    case 2:
        engine_type = "Electric";
        break;
    case 3:
        engine_type = "Diezel";
        break;
    case 4:
        engine_type = "Gazoline";
        break;
    default:
        cout << "Invalid choice. Setting vehicle type to Diezel by default.\n";
        engine_type = "Diezel";
    }
    return engine_type;
}

void VehicleList::addTransport() {
    Vehicle* current = head;
    cout << "Enter your surname: ";
    string surname;
    cin >> surname;
    string phone_number;
    string name;
    bool found = false;

    while (current != nullptr) {
        if (current->surname == surname) {
            name = current->name;
            phone_number = current->phone_number;
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        cout << "Enter mark of your car: ";
        string vehicle_name;
        cin >> vehicle_name;
        Transport* newTransport = new Transport();
        newTransport->name = name;
        newTransport->surname = surname;
        newTransport->phone_number = phone_number;
        newTransport->vehicle_name = vehicle_name;
        string vehicle_type = chooseVehicleType();
        newTransport->vehicle_type = vehicle_type;
        string engine_type = chooseEngineType();
        newTransport->engine_type = engine_type;
        string problem = chooseProblems(vehicle_type, engine_type);
        newTransport->problem = problem;
        newTransport->next = head;
        head = newTransport;
    }
    else {
        cout << "User with this surname not found!\n";
    }
}

void VehicleList::displayInfo() {
    string surname;
    cout << "Enter your surname: ";
    cin >> surname;
    Vehicle* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->surname == surname) {
            cout << "Information for " << current->name << " " << current->surname << ":\n\n";
            cout << "Name: " << current->name << endl;
            cout << "Surname: " << current->surname << endl;
            cout << "Phone Number: " << current->phone_number << endl;
            found = true;
            cout << endl;
            break;
        }
        current = current->next;
    }

    if (found) {
        Transport* currentTransport = dynamic_cast<Transport*>(head);
        while (currentTransport != nullptr) {
            if (currentTransport->surname == surname) {
                cout << "Mark: " << currentTransport->vehicle_name << endl;
                cout << "Vehicle Type: " << currentTransport->vehicle_type << endl;
                cout << "Engine Type: " << currentTransport->engine_type << endl;
                cout << "Problem: " << currentTransport->problem << endl;
                cout << endl;
            }
            currentTransport = dynamic_cast<Transport*>(currentTransport->next);
        }
    }
    else {
        cout << "User with this surname not found!\n";
    }
}

void VehicleList::deleteTransport(const string& vehicle_name) {
    Transport* prevTransport = nullptr;
    Transport* currentTransport = dynamic_cast<Transport*>(head);

    while (currentTransport != nullptr) {
        if (currentTransport->vehicle_name == vehicle_name) {
            if (prevTransport == nullptr) {
                head = currentTransport->next;
            }
            else {
                prevTransport->next = currentTransport->next;
            }
            delete currentTransport;
            break;
        }
        prevTransport = currentTransport;
        currentTransport = dynamic_cast<Transport*>(currentTransport->next);
    }
}

void VehicleList::deleteUser(const string& surname) {
    Vehicle* prevUser = nullptr;
    Vehicle* currentUser = head;

    while (currentUser != nullptr) {
        if (currentUser->surname == surname) {
            if (prevUser == nullptr) {
                head = currentUser->next;
            }
            else {
                prevUser->next = currentUser->next;
            }
            delete currentUser;
            break;
        }
        prevUser = currentUser;
        currentUser = currentUser->next;
    }
}

void VehicleList::deleteTransportOrUser() {
    string vehicle_name;
    cout << "Enter the name of the vehicle to delete: ";
    cin >> vehicle_name;

    Transport* currentTransport = dynamic_cast<Transport*>(head);
    Transport* prevTransport = nullptr;
    bool transportFound = false;

    while (currentTransport != nullptr) {
        if (currentTransport->vehicle_name == vehicle_name) {
            transportFound = true;
            deleteTransport(vehicle_name); 
            cout << "Transport with name " << vehicle_name << " deleted.\n";
            break;
        }
        prevTransport = currentTransport;
        currentTransport = dynamic_cast<Transport*>(currentTransport->next);
    }

    if (!transportFound) {
        cout << "Transport with name " << vehicle_name << " not found.\n";
        return;
    }

    string surname = prevTransport != nullptr ? prevTransport->surname : head->surname;
    bool userHasTransport = false;

    currentTransport = dynamic_cast<Transport*>(head);
    while (currentTransport != nullptr) {
        if (currentTransport->surname == surname) {
            userHasTransport = true;
            break;
        }
        currentTransport = dynamic_cast<Transport*>(currentTransport->next);
    }

    if (!userHasTransport) {
        deleteUser(surname); 
        cout << "User with surname " << surname << " deleted as they have no transport left.\n";
    }
}


string chooseProblems(string vehicle_type, string engine_type) {
    int problemNumber = 1;
    string problems[100];

    for (const auto& generalProblem : Problem::DefaultProblems) {
        cout << problemNumber << ". " << generalProblem << endl;
        problems[problemNumber - 1] = generalProblem;
        problemNumber++;
    }

    if (vehicle_type == "Motorcycle") {
        for (const auto& motoProblem : MotoProblem::motoProblems) {
            cout << problemNumber << ". " << motoProblem.description << endl;
            problems[problemNumber - 1] = motoProblem.description;
            problemNumber++;
        }

        if (engine_type == "Gas") {
            for (const auto& motoEngineProblem : MotoProblem::motoGasProblems) {
                cout << problemNumber << ". " << motoEngineProblem << endl;
                problems[problemNumber - 1] = motoEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Electric") {
            for (const auto& motoEngineProblem : MotoProblem::motoElectricProblems) {
                cout << problemNumber << ". " << motoEngineProblem << endl;
                problems[problemNumber - 1] = motoEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Gasoline") {
            for (const auto& motoEngineProblem : MotoProblem::motoGasolineProblems) {
                cout << problemNumber << ". " << motoEngineProblem << endl;
                problems[problemNumber - 1] = motoEngineProblem;
                problemNumber++;
            }
        }
    }

    if (vehicle_type == "Car") {
        for (const auto& carProblem : CarProblem::carProblems) {
            cout << problemNumber << ". " << carProblem.description << endl;
            problems[problemNumber - 1] = carProblem.description;
            problemNumber++;
        }

        if (engine_type == "Gas") {
            for (const auto& carEngineProblem : CarProblem::carGas) {
                cout << problemNumber << ". " << carEngineProblem << endl;
                problems[problemNumber - 1] = carEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Electric") {
            for (const auto& carEngineProblem : CarProblem::carElectric) {
                cout << problemNumber << ". " << carEngineProblem << endl;
                problems[problemNumber - 1] = carEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Diezel") {
            for (const auto& carEngineProblem : CarProblem::carDiezel) {
                cout << problemNumber << ". " << carEngineProblem << endl;
                problems[problemNumber - 1] = carEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Gasoline") {
            for (const auto& carEngineProblem : CarProblem::carGasoline) {
                cout << problemNumber << ". " << carEngineProblem << endl;
                problems[problemNumber - 1] = carEngineProblem;
                problemNumber++;
            }
        }
    }

    if (vehicle_type == "Truck") {
        for (const auto& truckProblem : TruckProblem::truckProblems) {
            cout << problemNumber << ". " << truckProblem.description << endl;
            problems[problemNumber - 1] = truckProblem.description;
            problemNumber++;
        }

        if (engine_type == "Gas") {
            for (const auto& truckEngineProblem : TruckProblem::truckGas) {
                cout << problemNumber << ". " << truckEngineProblem << endl;
                problems[problemNumber - 1] = truckEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Electric") {
            for (const auto& truckEngineProblem : TruckProblem::truckElectric) {
                cout << problemNumber << ". " << truckEngineProblem << endl;
                problems[problemNumber - 1] = truckEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Diezel") {
            for (const auto& truckEngineProblem : TruckProblem::truckDiezel) {
                cout << problemNumber << ". " << truckEngineProblem << endl;
                problems[problemNumber - 1] = truckEngineProblem;
                problemNumber++;
            }
        }
        if (engine_type == "Gasoline") {
            for (const auto& truckEngineProblem : TruckProblem::truckGasoline) {
                cout << problemNumber << ". " << truckEngineProblem << endl;
                problems[problemNumber - 1] = truckEngineProblem;
                problemNumber++;
            }
        }
    }
    int temp;
    do {
        cout << "Choose your problems: ";
        cin >> temp;
    } while (temp > problemNumber);
    cout << endl;

    return problems[temp - 1];
}