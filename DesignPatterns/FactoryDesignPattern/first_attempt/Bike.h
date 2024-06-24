//
// Created by hayley on 2024/06/24.
//

#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"
#include <string>

class Bike : public Vehicle {
public:
    std::string getType() override;
};



#endif //BIKE_H
