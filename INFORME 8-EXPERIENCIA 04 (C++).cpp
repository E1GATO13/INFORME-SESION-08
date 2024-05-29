#include <iostream>
using namespace std;

class Vehiculo {
public:
    virtual void acelerar() {
        cout << "Acelerando el vehículo" <<endl;
    }
};

class Coche : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando el coche" <<endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas\n" <<endl;
    }
};

class Motocicleta : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando la motocicleta" <<endl;
    }
};

int main() {
    Coche coche1;
    coche1.acelerar();
    coche1.encenderLuces();

    Motocicleta moto1;
    moto1.acelerar();

    return 0;
}
