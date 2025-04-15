//  «адача1 OCP : –азработайте систему дл€ расчета стоимости производства
//  различных типов машин(например, легковые, грузовые, спортивные), котора€
//  позвол€ет добавл€ть новые модели без изменени€ существующего кода.—оздайте
//  интерфейс VehicleCostCalculator и реализуйте различные классы дл€ каждого типа
//  транспортного средства.

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class VehicleCostCalculator  // интерфейс 
{
public:
    virtual double calculateCost() const = 0; 
};

class Sedan : public VehicleCostCalculator  // класс легкового авто
{
private:
    double baseCost;
    double seatsCost;
    double interiorCost;

public:
    Sedan(double baseCost, double seatsCost, double interiorCost) 
        : baseCost(baseCost), seatsCost(seatsCost), interiorCost(interiorCost) {}

    double calculateCost() const override
    {
        return baseCost + seatsCost + interiorCost;
    }
};

class Truck : public VehicleCostCalculator  // класс грузовика
{
private:
    double baseCost;
    double tiresCost;

public:
    Truck(double baseCost, double tiresCost) : baseCost(baseCost), tiresCost(tiresCost) {}

    double calculateCost() const override
    {
        return baseCost + tiresCost;
    }
};

class SportsCar : public VehicleCostCalculator  // класс спортивное авто
{
private:
    double baseCost;
    double engineCost;

public:
    SportsCar(double baseCost, double engineCost) : baseCost(baseCost), engineCost(engineCost) {}

    double calculateCost() const override
    {
        return baseCost + engineCost;
    }
};


class VehicleCostManager  // cистема дл€ расчета стоимости производства различных машин
{
private:
    vector<unique_ptr<VehicleCostCalculator>> vehicles;

public:
    void addVehicle(unique_ptr<VehicleCostCalculator> vehicle)
    {
        vehicles.push_back(move(vehicle)); // move дл€ передачи другому unique_ptr
    }

    void showAllCosts() const
    {
        double cost = 0;
        //for (const auto& vehicle : vehicles)
        for (int i = 0; i < vehicles.size(); i++)
        {
            cout << "÷ена " << i << "го транспорта: " << vehicles[i]->calculateCost() << endl;
        }
    }
};