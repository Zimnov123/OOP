#include "pch.h" 
#include "vehicle.h"
#include "vehicle_di_container.h"

TEST(VehicleListTest, AddTransportTest) {

    VehicleDIContainer container;
    VehicleList vehicleList;

    std::string name = "Oleksandr";
    std::string surname = "Zimnov";
    std::string phone_number = "0631761061";
    std::string vehicle_name = "Toyota";
    std::string vehicle_type = "Car";
    std::string engine_type = "Gas";
    std::string problem = "Engine starting issues";

    Vehicle* user = new Vehicle(name, surname, phone_number);
    container.registerDependency("user", user);

    vehicleList.addUser(&container);

    vehicleList.addTransport(&container);

    ASSERT_NE(vehicleList.getHead(), nullptr);

    if (vehicleList.getHead() != nullptr) {
        bool transportFound = false;
        Vehicle* currentUser = vehicleList.getHead();
        while (currentUser != nullptr) {
            Transport* addedTransport = dynamic_cast<Transport*>(currentUser);
            if (addedTransport != nullptr && addedTransport->vehicle_name == vehicle_name &&
                addedTransport->vehicle_type == vehicle_type &&
                addedTransport->engine_type == engine_type &&
                addedTransport->problem == problem) {
                transportFound = true;
                break;
            }
            currentUser = currentUser->next;
        }
        ASSERT_TRUE(transportFound) << "Added transport does not match the expected values.";
    }
    else {
        FAIL() << "Failed to add transport to the list.";
    }
}

