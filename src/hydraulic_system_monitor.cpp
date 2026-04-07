#include <string>

class HydraulicSystemMonitor
{
private:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;

public:
    HydraulicSystemMonitor()
    {
        hydraulic_oil_temperature = "45C";
        hydraulic_oil_tank_fill_level = "100%";
        hydraulic_oil_pressure = "250 bar";
    }

    std::string getOilTemperature()
    {
        return hydraulic_oil_temperature;
    }

    std::string getOilTankFillLevel()
    {
        return hydraulic_oil_tank_fill_level;
    }

    std::string getOilPressure()
    {
        return hydraulic_oil_pressure;
    }
};