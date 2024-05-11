#pragma once

#include<iostream>

namespace CST8219 {

    class Vehicle {
    public:
     
        Vehicle();
        Vehicle(int w);
        Vehicle(int w, int d);
        Vehicle(const Vehicle& copy);
        Vehicle(const Vehicle* copy);
        ~Vehicle();

        void printVehicle() const;
        int getNumWheels() const;
        void setNumWheels(int w);
        int getNumDoors() const;
        void setNumDoors(int d);


        //Assignment operator
        Vehicle& operator=(const Vehicle& other);
        //comparison operators
        bool operator==(const Vehicle& other) const;
        bool operator!=(const Vehicle& other) const;
        // increment and decrement operators
        Vehicle& operator++();
        Vehicle operator++(int);
        Vehicle& operator--();
        Vehicle operator--(int);

        // output operator as friend
        friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

        Vehicle(int w, int d, float maximum, float efficiency);
        virtual ~Vehicle();

        void printVehicle() const;
        int getNumWheels() const;
        void setNumWheels(int w);
        int getNumDoors() const;
        void setNumDoors(int d);
        float getEngineEfficiency() const;
        void setEngineEfficiency(float efficiency);
        virtual float calculateRange() = 0;
        virtual float percentEnergyRemaining() = 0;
        virtual void drive(float km) = 0;

        virtual float calculateRange() = 0;
        virtual float percentEnergyRemaining() = 0;
        virtual void drive(float km) = 0;

    private:
        int numWheels;
        int numDoors;
        float engineEfficiency;
        float currentEnergy; 
        float maximumEnergy; 

    };
}