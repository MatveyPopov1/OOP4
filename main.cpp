#include <iostream>
#include "srp.cpp"
#include "ocp.cpp"
#include "isp.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    Engine engine(200, 300, 8.5f);
    Transmission transmission("Авто");
    CoolingSystem coolingSystem(95.0f);

    engine.displayInfo();
    cout << "\n";
    transmission.displayInfo();
    cout << "\n";
    coolingSystem.displayInfo();
    coolingSystem.coolDown();
    coolingSystem.displayInfo();

    cout << "\n\n";

    VehicleCostManager manager;

    manager.addVehicle(make_unique<Sedan>(20000, 2000, 10000));
    manager.addVehicle(make_unique<Truck>(40000, 5000));
    manager.addVehicle(make_unique<SportsCar>(50000, 10000));

    manager.showAllCosts();

    showISPExample();

    return 0;
}