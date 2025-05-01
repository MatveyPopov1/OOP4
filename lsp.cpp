#include <iostream>
using namespace std;


class Vehicle
{
public:
    virtual void startEngine() const = 0;
    virtual void stopEngine() const = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle
{
public:
    void startEngine() const override
    {
        cout << "Двигатель автомобиля запущен" << endl;
    }

    void stopEngine() const override
    {
        cout << "Двигатель автомобиля остановлен" << endl;
    }
};


class Truck : public Vehicle
{
public:
    void startEngine() const override
    {
        cout << "Двигатель грузовика запущен" << endl;
    }

    void stopEngine() const override
    {
        cout << "Двигатель грузовика остановлен" << endl;
    }
};


class Motorcycle : public Vehicle
{
public:
    void startEngine() const override
    {
        cout << "Двигатель мотоцикла запущен" << endl;
    }

    void stopEngine() const override
    {
        cout << "Двигатель мотоцикла остановлен" << endl;
    }
};


void testVehicle(const Vehicle& vehicle)
{
    vehicle.startEngine();
    vehicle.stopEngine();
}

int main()
{
    setlocale(LC_ALL, "");
    Car car;
    Truck truck;
    Motorcycle motorcycle;

    testVehicle(car);
    testVehicle(truck);
    testVehicle(motorcycle);

}
