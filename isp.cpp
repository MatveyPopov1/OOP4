#include <iostream>
using namespace std;

class IEngineVehicle {
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Accelerate() = 0;
    virtual ~IEngineVehicle() = default;
};

class IFlyable {
public:
    virtual void Fly() = 0;
    virtual ~IFlyable() = default;
};

class ISailable {
public:
    virtual void Sail() = 0;
    virtual ~ISailable() = default;
};

class Car : public IEngineVehicle {
public:
    void Start() override { cout << "Машина завелась\n"; }
    void Stop() override { cout << "Машина остановилась\n"; }
    void Accelerate() override { cout << "Машина ускоряется\n"; }
};

class Airplane : public IEngineVehicle, public IFlyable {
public:
    void Start() override { cout << "Самолёт запущен\n"; }
    void Stop() override { cout << "Самолёт остановлен\n"; }
    void Accelerate() override { cout << "Самолёт ускоряется\n"; }
    void Fly() override { cout << "Самолёт летит\n"; }
};

class Ship : public IEngineVehicle, public ISailable {
public:
    void Start() override { cout << "Корабль запущен\n"; }
    void Stop() override { cout << "Корабль остановлен\n"; }
    void Accelerate() override { cout << "Корабль ускоряется\n"; }
    void Sail() override { cout << "Корабль плывёт\n"; }
};

void showISPExample() {
    cout << "--- Пример Interface Segregation Principle ---\n\n";

    Car car;
    car.Start();
    car.Accelerate();
    car.Stop();

    cout << "\n";

    Airplane plane;
    plane.Start();
    plane.Accelerate();
    plane.Fly();
    plane.Stop();

    cout << "\n";

    Ship ship;
    ship.Start();
    ship.Accelerate();
    ship.Sail();
    ship.Stop();

    cout << "\n----------------------------------------------\n\n";
}