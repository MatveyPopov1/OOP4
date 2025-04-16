//  ������1 OCP : ������������ ������� ��� ������� ��������� ������������
//  ��������� ����� �����(��������, ��������, ��������, ����������), �������
//  ��������� ��������� ����� ������ ��� ��������� ������������� ����.��������
//  ��������� VehicleCostCalculator � ���������� ��������� ������ ��� ������� ����
//  ������������� ��������.

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class VehicleCostCalculator  // ��������� 
{
public:
    virtual double calculateCost() const = 0; 
};

class Sedan : public VehicleCostCalculator  // ����� ��������� ����
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

class Truck : public VehicleCostCalculator  // ����� ���������
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

class SportsCar : public VehicleCostCalculator  // ����� ���������� ����
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


class VehicleCostManager  // c������ ��� ������� ��������� ������������ ��������� �����
{
private:
    vector<unique_ptr<VehicleCostCalculator>> vehicles;

public:
    void addVehicle(unique_ptr<VehicleCostCalculator> vehicle)
    {
        vehicles.push_back(move(vehicle)); // move ��� �������� ������� unique_ptr
    }

    void showAllCosts() const
    {
        double cost = 0;
        //for (const auto& vehicle : vehicles)
        for (int i = 0; i < vehicles.size(); i++)
        {
            cout << "���� " << i << "�� ����������: " << vehicles[i]->calculateCost() << endl;
        }
    }
};