#include <iostream>

using namespace std;

class Figura {
public:
    virtual double calcularArea() = 0;
};

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return 3.14 * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double b) : ancho(a), alto(b) {}
    double calcularArea() override {
        return ancho * alto;
    }
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};

class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() override {
        return lado * lado;
    }
};

class Pentagono : public Figura {
private:
    double lado, apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() override {
        return (5 * lado * apotema) / 2;
    }
};

int main() {
    Figura* figura = nullptr;
    int opcion;

    cout << "Seleccione una figura:\n";
    cout << "1. Circulo\n";
    cout << "2. Rectangulo\n";
    cout << "3. Triangulo\n";
    cout << "4. Cuadrado\n";
    cout << "5. Pentagono\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double ancho, alto;
            cout << "Ingrese el ancho del rectangulo: ";
            cin >> ancho;
            cout << "Ingrese el alto del rectangulo: ";
            cin >> alto;
            figura = new Rectangulo(ancho, alto);
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese la base del triangulo: ";
            cin >> base;
            cout << "Ingrese la altura del triangulo: ";
            cin >> altura;
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            double lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            double lado, apotema;
            cout << "Ingrese el lado del pentagono: ";
            cin >> lado;
            cout << "Ingrese la apotema del pentagono: ";
            cin >> apotema;
            figura = new Pentagono(lado, apotema);
            break;
        }
        default:
            cout << "Opcion no valida." << endl;
            return 1;
    }

    cout << "El area de la figura es: " << figura->calcularArea() << endl;

    delete figura;
    return 0;
}


