#include <iostream>

#include "BikeFactory.h"
#include "CarFactory.h"
#include "TruckFactory.h"
#include "VehicleFactory.h"

int main() {
    VehicleFactory carFactory = new CarFactory();
    VehicleFactory bikeFactory = new BikeFactory();
    VehicleFactory truckFactory = new TruckFactory();


    return 0;
}
