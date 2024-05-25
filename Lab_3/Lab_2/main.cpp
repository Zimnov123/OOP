#include <iostream>
#include "vehicle.h"
#include "vehicle_di_container.h"

int main() {
    VehicleDIContainer container;

    VehicleList vehicleList;

    int choice;
    do {
        cout << "1. Add user\n";
        cout << "2. Add transport\n";
        cout << "3. Display transport\n";
        cout << "4. Delete transport\n";
        cout << "5. Delete user\n";
        cout << "6. Exit\n";
        cout << "Choose your option: ";
        cin >> choice;
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            vehicleList.addUser(&container);
            break;
        case 2:
            vehicleList.addTransport(&container);
            break;
        case 3:
            vehicleList.displayInfo(&container);
            break;
        case 4:
            vehicleList.deleteTransport(&container); 
            break;
        case 5:
            vehicleList.deleteUser(&container);
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
