
#include "Vehicle.h"

using namespace std;
using namespace CST8219;

Vehicle::Vehicle() : numWheels(0), numDoors(0) {}

Vehicle::Vehicle(int w) : numWheels(w), numDoors(0) {}

Vehicle::Vehicle(int w, int d) : numWheels(w), numDoors(d) {}

Vehicle::Vehicle(const Vehicle& copy) : numWheels(copy.numWheels), numDoors(copy.numDoors) {}

Vehicle::Vehicle(Vehicle&& move) noexcept : numWheels(move.numWheels), numDoors(move.numDoors) {
    move.numWheels = 0;
    move.numDoors = 0;
}

Vehicle::~Vehicle() {}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        numWheels = other.numWheels;
        numDoors = other.numDoors;
    }
    return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) {
    if (this != &other) {
        numWheels = other.numWheels;
        numDoors = other.numDoors;
        other.numWheels = 0;
        other.numDoors = 0;
    }
    return *this;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return (numWheels == other.numWheels) && (numDoors == other.numDoors);
}

bool Vehicle::operator!=(const Vehicle& other) const {
    return !(*this == other);
}

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

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << "Number of wheels: " << v.numWheels << ", Number of doors: " << v.numDoors;
    return os;
}

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
