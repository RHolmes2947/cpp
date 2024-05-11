#pragma once

#include "Vehicle.h"

namespace CST8219 {

    class GasolineVehicle : public Vehicle {
    public:
        GasolineVehicle(int w, int d, float current, float maximum, float efficiency);
        virtual ~GasolineVehicle();

        float calculateRange() override;
        float percentEnergyRemaining() override;
        void drive(float km) override;

    private:
        float currentGasoline;
        float maximumGasoline;
    };

}
