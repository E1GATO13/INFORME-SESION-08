#include <iostream>
using namespace std;

class Forma {
public:
    virtual double calcularPerimetro() const = 0;
};

class Circulo : public Forma {
private:
    double radio;
    static constexpr double PI = 3.1416;
public:
    Circulo(double r) : radio(r) {}

    double calcularPerimetro() const override {
        return 2 * PI * radio;
    }
};

class Rectangulo : public Forma {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}

    double calcularPerimetro() const override {
        return 2 * (largo + ancho);
    }
};

class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}

    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
};

Forma* crearForma(int seleccion) {
    switch (seleccion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            return new Circulo(radio);
        }
        case 2: {
            double largo, ancho;
            cout << "Ingrese el largo del rectángulo: ";
            cin >> largo;
            cout << "Ingrese el ancho del rectángulo: ";
            cin >> ancho;
            return new Rectangulo(largo, ancho);
        }
        case 3: {
            double lado1, lado2, lado3;
            cout << "Ingrese el primer lado del triángulo: ";
            cin >> lado1;
            cout << "Ingrese el segundo lado del triángulo: ";
            cin >> lado2;
            cout << "Ingrese el tercer lado del triángulo: ";
            cin >> lado3;
            return new Triangulo(lado1, lado2, lado3);
        }
        default:
            cout << "Selección inválida.\n";
            return 0;
    }
}

int main() {
    char continuar;
    do {
        int opc;
        bool opcValida = false;

        while (!opcValida) {
            cout << "Seleccione una forma para calcular su perímetro:\n";
            cout << "1. Círculo\n";
            cout << "2. Rectángulo\n";
            cout << "3. Triángulo\n";
            cout << "Ingrese su selección: ";
            cin >> opc;

            if (opc >= 1 && opc <= 3) {
                opcValida = true;
            } else {
                cout << "Por favor, intente de nuevo.\n";
            }
        }

        Forma* forma = crearForma(opc);
    
        cout << "El perímetro de la forma seleccionada es: " << forma->calcularPerimetro() << endl;
        delete forma;
        

        cout << "¿Desea calcular el perímetro de otra forma? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}