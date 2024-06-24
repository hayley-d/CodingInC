//
// Created by hayley on 2024/06/24.
//

#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include <string>

class Truck : public Vehicle{
    std::string getType() override;
};



#endif //TRUCK_H
