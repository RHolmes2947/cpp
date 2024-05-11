#pragma once

#include "GasolineVehicle.h"
#include "ElectricVehicle.h"

namespace CST8219 {

    class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
    public:
        HybridVehicle(int w, int d, float gasCurrent, float gasMaximum, float gasEfficiency, float electricCurrent, float electricMaximum, float electricEfficiency);
        virtual ~HybridVehicle();

        float calculateRange() override;
        float percentEnergyRemaining() override;
        void drive(float km) override;
    };

}
