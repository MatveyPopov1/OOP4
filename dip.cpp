#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

// Интерфейс для сборочной линии
class AssemblyLine {
public:
    virtual void assembleVehicle() const = 0;
    virtual ~AssemblyLine() = default;
};

// Конкретная реализация сборочной линии A
class AssemblyLineA : public AssemblyLine {
public:
    void assembleVehicle() const override {
        cout << "Сборочная линия A: Сборка автомобиля на линии A.\n";
    }
};

// Конкретная реализация сборочной линии B
class AssemblyLineB : public AssemblyLine {
public:
    void assembleVehicle() const override {
        cout << "Сборочная линия B: Сборка автомобиля на линии B.\n";
    }
};

// Класс, который управляет процессом производства
class ProductionManager {
private:
    unique_ptr<AssemblyLine> assemblyLine; // зависит от абстракции

public:
    // Устанавливаем конкретную сборочную линию
    void setAssemblyLine(unique_ptr<AssemblyLine> line) {
        assemblyLine = move(line);
    }

    // Запуск сборки на выбранной линии
    void startProduction() const {
        if (assemblyLine) {
            assemblyLine->assembleVehicle();
        }
        else {
            cout << "Не выбрана сборочная линия.\n";
        }
    }
};
