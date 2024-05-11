#include <iostream>
#include "Vehicle.h"
#include "ElectricVehicle.h"
#include "GasolineVehicle.h"
#include "HybridVehicle.h"

using namespace std;
using namespace CST8219;

Vehicle* testVehicle(Vehicle* pVehicle, const char* vehicleName) {
    cout << vehicleName << "'s range is: " << pVehicle->calculateRange() << endl;
    pVehicle->drive(150); //drive 150 km
    cout << vehicleName << "'s energy left is: " << pVehicle->percentEnergyRemaining() << endl;
    cout << vehicleName << "'s range is now: " << pVehicle->calculateRange() << endl;
    return pVehicle;
}

int main(int argc, char** argv) {
    // 50L of gas, 7.1 L/100km
    delete testVehicle(new GasolineVehicle(50, 0, 50, 7.1), "Corolla");

    // 42 L of gas, 4.3 L/100km, 8.8 kWh, 22 kWh/100km
    delete testVehicle(new HybridVehicle(0, 0, 42, 42, 4.3, 8.8, 22.0), "Prius");

    // 75 kWh, 16 kWh/100km
    delete testVehicle(new ElectricVehicle(0, 0, 75, 75, 16), "Tesla 3");

    return 0;
}
