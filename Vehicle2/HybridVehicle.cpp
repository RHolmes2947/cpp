#include "HybridVehicle.h"

using namespace CST8219;
using namespace std;

HybridVehicle::HybridVehicle(int w, int d, float gasCurrent, float gasMaximum, float gasEfficiency, float electricCurrent, float electricMaximum, float electricEfficiency)
    : Vehicle(w, d, gasMaximum, gasEfficiency), GasolineVehicle(w, d, gasCurrent, gasMaximum, gasEfficiency),
    ElectricVehicle(w, d, electricCurrent, electricMaximum, electricEfficiency) {}

HybridVehicle::~HybridVehicle() {
    cout << "In Hybrid Destructor" << endl;
}

float HybridVehicle::calculateRange() {
    float averageRange = (GasolineVehicle::calculateRange() + ElectricVehicle::calculateRange()) / 2;
    return averageRange;
}

float HybridVehicle::percentEnergyRemaining() {
    float averagePercent = (GasolineVehicle::percentEnergyRemaining() + ElectricVehicle::percentEnergyRemaining()) / 2;
    return averagePercent;
}

void HybridVehicle::drive(float km) {
    if (ElectricVehicle::percentEnergyRemaining() > 0.0f) {
        ElectricVehicle::drive(km);
    }
    else {
        GasolineVehicle::drive(km);
    }
}
