/*3. EXPERIENCIA DE PRÁCTICA N° 03: MÉTODOS VIRTUALES
1. Descripción: En esta experiencia de práctica, los estudiantes trabajarán con métodos
virtuales para implementar polimorfismo en una jerarquía de clases. El objetivo es
comprender cómo los métodos virtuales permiten la redefinición de comportamientos en las
clases derivadas.
2. Crea una clase base llamada "Animal" con un método virtual llamado "hacerSonido()". Esta
clase servirá como base para diferentes tipos de animales.
3. Crea al menos dos clases derivadas de "Animal", por ejemplo, "Perro" y "Gato". En cada
clase derivada, redefine el método "hacerSonido()" para que cada animal haga un sonido
diferente.
4. Implementa un programa que cree instancias de diferentes animales (por ejemplo, un perro
y un gato) y llame al método "hacerSonido()". Utiliza polimorfismo para almacenar los
objetos en variables de tipo "Animal" y llamar al método correspondiente.
5. Ejecuta el programa y verifica que cada animal haga el sonido correcto, utilizando la
implementación adecuada en la clase derivada.
6. Agrega al menos una nueva clase derivada, por ejemplo, "Vaca", y redefine el método
"hacerSonido()" para que la vaca haga su propio sonido.
7. Modifica el programa para crear una instancia de la vaca y llamar al método "hacerSonido()".
Verifica que la vaca haga el sonido correcto utilizando la implementación adecuada en la
clase derivada*/

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual string hacerSonido() const = 0;
};

class Perro : public Animal {
public:
    string hacerSonido() const override {
        return "¡Guau!";
    }
};

class Gato : public Animal {
public:
    string hacerSonido() const override {
        return "¡Miau!";
    }
};

class Vaca : public Animal {
public:
    string hacerSonido() const override {
        return "¡Muuu!";
    }
};

void comprobarSonido(const Animal& animal, const string& sonidoEsperado) {
    if (animal.hacerSonido() == sonidoEsperado) {
        cout << "¡Correcto! El sonido es: " << animal.hacerSonido() << endl;
    } else {
        cout << "Incorrecto. El sonido es: " << animal.hacerSonido() << endl;
    }
}

int main() {
    int opcion;
    string sonidoEsperado;

    Perro perro;
    Gato gato;
    Vaca vaca;

    while (true) {
        cout << "Seleccione un animal para escuchar su sonido:" << endl;
        cout << "1. Perro" << endl;
        cout << "2. Gato" << endl;
        cout << "3. Vaca" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        if (opcion == 4) {
            break;
        }

        cout << "Ingrese el sonido esperado: ";
        cin >> sonidoEsperado;

        switch (opcion) {
            case 1:
                comprobarSonido(perro, sonidoEsperado);
                break;
            case 2:
                comprobarSonido(gato, sonidoEsperado);
                break;
            case 3:
                comprobarSonido(vaca, sonidoEsperado);
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    }

    return 0;
}



