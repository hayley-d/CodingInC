//
// Created by hayley on 2024/06/24.
//

#ifndef BIKEFACTORY_H
#define BIKEFACTORY_H

#include "VehicleFactory.h"
#include "Bike.h"

class BikeFactory : public VehicleFactory{
    Vehicle* createVehicle() override {
        return new Bike();
    }
};



#endif //BIKEFACTORY_H
