#include "GasolineVehicle.h"

using namespace CST8219;

GasolineVehicle::GasolineVehicle(int w, int d, float current, float maximum, float efficiency) : Vehicle(w, d, maximum, efficiency), currentGasoline(current), maximumGasoline(maximum) {}

GasolineVehicle::~GasolineVehicle() {
    cout << "In Gasoline Destructor" << endl;
}

float GasolineVehicle::calculateRange() {
    return (currentGasoline * 100) / getEngineEfficiency();
}

float GasolineVehicle::percentEnergyRemaining() {
    return (currentGasoline / maximumGasoline) * 100.0f;
}

void GasolineVehicle::drive(float km) {
    currentGasoline -= (km / 100.0f) * getEngineEfficiency();
    if (currentGasoline < 0.0f) {
        std::cout << "Your car is out of energy!" << std::endl;
        currentGasoline = 0.0f;
    }
}
