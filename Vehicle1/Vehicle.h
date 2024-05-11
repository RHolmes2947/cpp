// Vehicle.h
#pragma once
#include<iostream>

namespace CST8219 {

    class Vehicle {
    public:
        Vehicle();
        Vehicle(int w);
        Vehicle(int w, int d);
        Vehicle(const Vehicle& copy); // Copy constructor
        Vehicle(Vehicle&& move); // Move constructor
        ~Vehicle();

        // Assignment operator
        Vehicle& operator=(const Vehicle& other);
        // Move assignment operator
        Vehicle& operator=(Vehicle&& other);

        // Comparison operators
        bool operator==(const Vehicle& other) const;
        bool operator!=(const Vehicle& other) const;

        // Increment and decrement operators
        Vehicle& operator++();     // Prefix increment
        Vehicle operator++(int);   // Postfix increment
        Vehicle& operator--();     // Prefix decrement
        Vehicle operator--(int);   // Postfix decrement

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

        void printVehicle() const;
        int getNumWheels() const;
        void setNumWheels(int w);
        int getNumDoors() const;
        void setNumDoors(int d);

    private:
        int numWheels;
        int numDoors;
    };

}
