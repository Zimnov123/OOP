#include <iostream>
#include "auto_service.h"
#include "car.h"
#include "truck.h"
#include "moto.h"

using namespace std;

int main() {
    AutoService autoService;
    VehicleList vehicleList;
    Vehicle* vehicle = new Car("gasoline");
    autoService.addVehicle(vehicle);
    vehicleList.addVehicle(vehicle);
    autoService.registerRepair(vehicle, "Engine repair", "Engine starting issues");
    autoService.displayRepairInfo("Engine starting issues");
    vehicleList.displayVehicles();
    vehicleList.removeVehicle(vehicle);
  //  autoService.serviceVehicles();
    return 0;
}
