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
    void Start() override { cout << "������ ��������\n"; }
    void Stop() override { cout << "������ ������������\n"; }
    void Accelerate() override { cout << "������ ����������\n"; }
};

class Airplane : public IEngineVehicle, public IFlyable {
public:
    void Start() override { cout << "������ �������\n"; }
    void Stop() override { cout << "������ ����������\n"; }
    void Accelerate() override { cout << "������ ����������\n"; }
    void Fly() override { cout << "������ �����\n"; }
};

class Ship : public IEngineVehicle, public ISailable {
public:
    void Start() override { cout << "������� �������\n"; }
    void Stop() override { cout << "������� ����������\n"; }
    void Accelerate() override { cout << "������� ����������\n"; }
    void Sail() override { cout << "������� �����\n"; }
};

void showISPExample() {
    cout << "--- ������ Interface Segregation Principle ---\n\n";

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