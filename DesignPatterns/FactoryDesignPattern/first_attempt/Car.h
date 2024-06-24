//
// Created by hayley on 2024/06/24.
//

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <string>

class Car : public Vehicle {
public:
    std::string getType() override;
};



#endif //CAR_H
