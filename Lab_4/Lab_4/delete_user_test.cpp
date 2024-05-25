#include <gtest/gtest.h>
#include "pch.h" 
#include <sstream> 
#include "vehicle.h"
#include "vehicle_di_container.h"

TEST(VehicleListTest, DeleteUserTest) {

    VehicleDIContainer container;
    VehicleList vehicleList;

    vehicleList.addUser(&container);

    vehicleList.deleteUser(&container);

    ASSERT_EQ(vehicleList.getHead(), nullptr);
}