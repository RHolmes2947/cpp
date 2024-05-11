#pragma once

#include "Vehicle.h"

namespace CST8219 {

    class ElectricVehicle : public Vehicle {
    public:
        ElectricVehicle(int w, int d, float current, float maximum, float efficiency);
        virtual ~ElectricVehicle();

        float calculateRange() override;
        float percentEnergyRemaining() override;
        void drive(float km) override;

    private:
        float currentCharge;
        float maximumCharge;
    };

}
