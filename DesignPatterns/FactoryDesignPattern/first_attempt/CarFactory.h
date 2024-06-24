//
// Created by hayley on 2024/06/24.
//

#ifndef CARFACTORY_H
#define CARFACTORY_H

#include "VehicleFactory.h"
#include "Car.h"


class CarFactory : public VehicleFactory{
    Vehicle* createVehicle() override {
        return new Car();
    }
};



#endif //CARFACTORY_H
