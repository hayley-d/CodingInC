cmake_minimum_required(VERSION 3.28)
project(FactoryDesignPattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(FactoryDesignPattern main.cpp
        Vehicle.cpp
        Vehicle.h
        Car.cpp
        Car.h
        Bike.cpp
        Bike.h
        Truck.cpp
        Truck.h
        VehicleFactory.cpp
        VehicleFactory.h
        CarFactory.cpp
        CarFactory.h
        BikeFactory.cpp
        BikeFactory.h
        TruckFactory.cpp
        TruckFactory.h)
