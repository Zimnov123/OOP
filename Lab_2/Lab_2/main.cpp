#include <iostream>
#include "vehicle.h"


int main() {

    VehicleList vehicleList;

    int choice;
    do {
        cout << "1. Add user\n";
        cout << "2. Add transport\n";
        cout << "3. Display transport\n";
        cout << "4. Delete transport\n";
        cout << "5. Exit\n";
        cout << "Choose your option: ";
        cin >> choice;
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            vehicleList.addUser();
            break;
        case 2:
            vehicleList.addTransport();
            break;
        case 3:
            vehicleList.displayInfo();
            break;
        case 4:
            vehicleList.deleteTransportOrUser();
            break;
        case 5:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
