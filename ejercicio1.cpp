#include <iostream>
#include <cmath>

using namespace std;

// Clase abstracta Figura
class Figura {
protected:
   string nombre;
public:
   Figura(string n) : nombre(n) {}
   virtual double calcularArea() = 0;
   virtual void dibujar() = 0;
};

// Clase derivada Círculo
class Circulo : public Figura {
private:
   double radio;
public:
   Circulo(double r) : Figura("Círculo"), radio(r) {}
   double calcularArea() {
       return M_PI * radio * radio;
   }
   void dibujar() {
       cout << "Dibujando un " << nombre << " de radio " << radio << endl;
   }
};

// Clase derivada Rectángulo
class Rectangulo : public Figura {
private:
   double base, altura;
public:
   Rectangulo(double b, double h) : Figura("Rectángulo"), base(b), altura(h) {}
   double calcularArea() {
       return base * altura;
   }
   void dibujar() {
       cout << "Dibujando un " << nombre << " de base " << base << " y altura " << altura << endl;
   }
};

// Clase derivada Triángulo
class Triangulo : public Figura {
private:
   double base, altura;
public:
   Triangulo(double b, double h) : Figura("Triángulo"), base(b), altura(h) {}
   double calcularArea() {
       return 0.5 * base * altura;
   }
   void dibujar() {
       cout << "Dibujando un " << nombre << " de base " << base << " y altura " << altura << endl;
   }
};

int main() {
   Figura* figuras[3];
   figuras[0] = new Circulo(5);
   figuras[1] = new Rectangulo(4, 6);
   figuras[2] = new Triangulo(3, 8);

   for (int i = 0; i < 3; i++) {
       figuras[i]->dibujar();
       cout << "Área: " << figuras[i]->calcularArea() << endl;
       cout << endl;
   }

   // Liberar memoria
   for (int i = 0; i < 3; i++) {
       delete figuras[i];
   }

   return 0;
}