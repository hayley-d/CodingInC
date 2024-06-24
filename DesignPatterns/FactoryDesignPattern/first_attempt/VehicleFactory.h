//
// Created by hayley on 2024/06/24.
//

#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H
#include "Vehicle.h"


class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() = default;
};



#endif //VEHICLEFACTORY_H
