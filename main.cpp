#include <iostream>
#include "srp.cpp"
#include "ocp.cpp"
#include "isp.cpp"
#include "dip.cpp"
#include "lsp.cpp"

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

    ProductionManager Productionmanager;

    // Устанавливаем первую сборочную линию и запускаем производство
    Productionmanager.setAssemblyLine(make_unique<AssemblyLineA>());
    Productionmanager.startProduction();

    cout << "\n";

    // Устанавливаем другую сборочную линию и снова запускаем производство
    Productionmanager.setAssemblyLine(make_unique<AssemblyLineB>());
    Productionmanager.startProduction();


    //lsp
    Car car;
    Truck truck;
    Motorcycle motorcycle;

    testVehicle(car);
    testVehicle(truck);
    testVehicle(motorcycle);


    return 0;
}