#include <iostream>
#include <string>
using namespace std;

// Параметры двигателя
class Engine {
private:
    int power;          
    int torque;         
    float fuelConsumption; 

public:
    Engine(int p, int t, float fc) : power(p), torque(t), fuelConsumption(fc) {}

    void setPower(int p) { power = p; }
    void setTorque(int t) { torque = t; }
    void setFuelConsumption(float fc) { fuelConsumption = fc; }
    int getPower() const { return power; }
    int getTorque() const { return torque; }
    float getFuelConsumption() const { return fuelConsumption; }

    void displayInfo() const {
        cout << "Информация о двигателе:\n";
        cout << "Мощность: " << power << " л.с.\n";
        cout << "Крутящий момент: " << torque << " Нм\n";
        cout << "Расход топлива: " << fuelConsumption << " л/100км\n";
    }
};

// Трансмиссия
class Transmission {
private:
    string type; 

public:
    Transmission(const string& t) : type(t) {}

    void setType(const string& t) { type = t; }
    string getType() const { return type; }

    void displayInfo() const {
        cout << "Тип трансмиссии: " << type << "\n";
    }
};

// Охлаждение
class CoolingSystem {
private:
    float temperature; 

public:
    CoolingSystem(float temp) : temperature(temp) {}

    void setTemperature(float temp) { temperature = temp; }
    float getTemperature() const { return temperature; }

    void coolDown() {
        if (temperature > 90.0f) {
            cout << "Активация системы охлаждения\n";
            while (temperature > 90.0f) {
                temperature -= 1.0f;
            }
        }
        else {
            cout << "Температура в порядке\n";
        }
    }

    void displayInfo() const {
        cout << "Температура двигателя: " << temperature << " C\n";
    }
};
