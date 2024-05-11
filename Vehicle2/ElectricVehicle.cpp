#include "ElectricVehicle.h"

using namespace CST8219;
using namespace std;

ElectricVehicle::ElectricVehicle(int w, int d, float current, float maximum, float efficiency) : Vehicle(w, d, maximum, efficiency), currentCharge(current), maximumCharge(maximum) {}

ElectricVehicle::~ElectricVehicle() {
    cout << "In Electric Destructor" << endl;
}



float ElectricVehicle::calculateRange() {
    return (currentCharge * 100) / getEngineEfficiency();
}

float ElectricVehicle::percentEnergyRemaining() {
    return (currentCharge / maximumCharge) * 100.0f;
}

void ElectricVehicle::drive(float km) {
    currentCharge -= (km / 100.0f) * getEngineEfficiency();
    if (currentCharge < 0.0f) {
        std::cout << "Your car is out of energy!" << std::endl;
        currentCharge = 0.0f;
    }

 
}
