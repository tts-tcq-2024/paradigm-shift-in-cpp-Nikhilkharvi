#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool validateTemperature(float temperature, std::string &message) {
    if (temperature < 0) {
        message = "Low temperature";
        return false;
    } else if (temperature > 45) {
        message = "High  temperature";
        return false;
    }
    return true;
}

bool validateSOC(float soc, std::string &message) {
    if (soc < 20) {
        message = "Low State of Charge";
        return false;
    } else if (soc > 80) {
        message = "High State of Charge";
        return false;
    }
    return true;
}

bool validateChargeRate(float chargeRate, std::string &message) {
    if (chargeRate > 0.8) {
        message = "High Charge Rate";
        return false;
    }
    return true;
}

bool checkInputs(float temperature, float soc, float chargeRate, std::string &message) {
    bool isTemperatureValid = validateTemperature(temperature, message);
    bool isSOCValid = validateSOC(soc, message);
    bool isChargeRateValid = validateChargeRate(chargeRate, message);
    return isTemperatureValid && isSOCValid && isChargeRateValid;
}

bool batteryIsOk(float temperature, float soc, float chargeRate, std::string &message) {
    bool allInputsValid = checkInputs(temperature, soc, chargeRate, message); 
    if (allInputsValid) {
        message = "Battery is OK.";
    }
    return allInputsValid;
}

void checkBatteryIsOk() {
    std::string message;
 
    assert(batteryIsOk(30, 60, 0.6, message) == true);
    assert(message == "Battery is OK.");
    assert(batteryIsOk(-10, 60, 0.6, message) == false);
    assert(message == "Low temperature");
    assert(batteryIsOk(60, 60, 0.6, message) == false);
    assert(message == "High  temperature");
    assert(batteryIsOk(30, 15, 0.6, message) == false);
    assert(message == "Low State of Charge");
    assert(batteryIsOk(30, 90, 0.6, message) == false);
    assert(message == "High State of Charge");
    assert(batteryIsOk(30, 60, 0.9, message) == false);
    assert(message == "High Charge Rate");
}
 
int main() {
    checkBatteryIsOk();
    cout << "All tests passed.\n";
    return 0;
}
