#include "Vehicle.h"

using namespace std;
using namespace CST8219;

Vehicle::Vehicle() : Vehicle(0, 0) {}

Vehicle::Vehicle(int w) : Vehicle(w, 0) {}

Vehicle::Vehicle(int w, int d) : numWheels(w), numDoors(d) {}

Vehicle::Vehicle(const Vehicle& copy) : Vehicle(copy.numWheels, copy.numDoors) {}

Vehicle::Vehicle(const Vehicle* copy) : Vehicle(copy->numWheels, copy->numDoors) {}

Vehicle::~Vehicle() {}

void Vehicle::printVehicle() const {
    cout << "Number of wheels: " << numWheels << ", Number of doors: " << numDoors << endl;
}

int Vehicle::getNumWheels() const {
    return numWheels;
}

void Vehicle::setNumWheels(int w) {
    numWheels = w;
}

int Vehicle::getNumDoors() const {
    return numDoors;
}

void Vehicle::setNumDoors(int d) {
    numDoors = d;
}

//Implementation of assignment operator
Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        numWheels = other.numWheels;
        numDoors = other.numDoors;
    }
    return *this;
}

//Implementation of comparison operators
bool Vehicle::operator==(const Vehicle& other) const {
    return (numWheels == other.numWheels) && (numDoors == other.numDoors);
}

bool Vehicle::operator!=(const Vehicle& other) const {
    return !(*this == other);
}
//Implementation of increment and decrement operators
Vehicle& Vehicle::operator++() {
    ++numWheels;
    ++numDoors;
    return *this;
}

Vehicle Vehicle::operator++(int) {
    Vehicle temp = *this;
    ++(*this);
    return temp;
}

Vehicle& Vehicle::operator--() {
    --numWheels;
    --numDoors;
    return *this;
}

Vehicle Vehicle::operator--(int) {
    Vehicle temp = *this;
    --(*this);
    return temp;
}

//Implementation of output operator
std::ostream& CST8219::operator<<(std::ostream& os, const Vehicle& v) {
    os << "Number of wheels: " << v.numWheels << ", Number of doors: " << v.numDoors;
    return os;
}
