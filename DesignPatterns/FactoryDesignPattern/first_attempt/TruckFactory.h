//
// Created by hayley on 2024/06/24.
//

#ifndef TRUCKFACTORY_H
#define TRUCKFACTORY_H

#include "VehicleFactory.h"
#include "Truck.h"

class TruckFactory : public VehicleFactory{
    Vehicle* createVehicle() override {
        return new Truck();
    }

};

#endif //TRUCKFACTORY_H

