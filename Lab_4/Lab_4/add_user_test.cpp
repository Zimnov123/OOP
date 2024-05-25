#include "pch.h" 
#include "vehicle.h"
#include "vehicle_di_container.h"
TEST(VehicleListTest, AddUserTest) {

    VehicleDIContainer container;
    VehicleList vehicleList;

    std::string name = "Oleksandr";
    std::string surname = "Zimnov";
    std::string phone_number = "0631761061";

    vehicleList.addUser(&container);

    ASSERT_NE(vehicleList.getHead(), nullptr);

    ASSERT_EQ(vehicleList.getHead()->name, name);
    ASSERT_EQ(vehicleList.getHead()->surname, surname);
    ASSERT_EQ(vehicleList.getHead()->phone_number, phone_number);
}