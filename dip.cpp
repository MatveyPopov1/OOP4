#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

// ��������� ��� ��������� �����
class AssemblyLine {
public:
    virtual void assembleVehicle() const = 0;
    virtual ~AssemblyLine() = default;
};

// ���������� ���������� ��������� ����� A
class AssemblyLineA : public AssemblyLine {
public:
    void assembleVehicle() const override {
        cout << "��������� ����� A: ������ ���������� �� ����� A.\n";
    }
};

// ���������� ���������� ��������� ����� B
class AssemblyLineB : public AssemblyLine {
public:
    void assembleVehicle() const override {
        cout << "��������� ����� B: ������ ���������� �� ����� B.\n";
    }
};

// �����, ������� ��������� ��������� ������������
class ProductionManager {
private:
    unique_ptr<AssemblyLine> assemblyLine; // ������� �� ����������

public:
    // ������������� ���������� ��������� �����
    void setAssemblyLine(unique_ptr<AssemblyLine> line) {
        assemblyLine = move(line);
    }

    // ������ ������ �� ��������� �����
    void startProduction() const {
        if (assemblyLine) {
            assemblyLine->assembleVehicle();
        }
        else {
            cout << "�� ������� ��������� �����.\n";
        }
    }
};
