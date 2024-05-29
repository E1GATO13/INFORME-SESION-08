#include <iostream>
#include <memory>

using namespace std;

class Empleado {
public:
    virtual double calcularSalario() const = 0; // Método virtual puro
    virtual ~Empleado() = default; // Destructor virtual
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    double salarioMensual;
public:
    EmpleadoTiempoCompleto(double salarioMensual) : salarioMensual(salarioMensual) {}

    double calcularSalario() const override {
        return salarioMensual;
    }
};

class EmpleadoMedioTiempo : public Empleado {
private:
    double salarioPorHora;
    int horasTrabajadas;
public:
    EmpleadoMedioTiempo(double salarioPorHora, int horasTrabajadas) 
        : salarioPorHora(salarioPorHora), horasTrabajadas(horasTrabajadas) {}

    double calcularSalario() const override {
        return salarioPorHora * horasTrabajadas;
    }
};

int main() {
    const int MAX_EMPLEADOS = 100;
    shared_ptr<Empleado> empleados[MAX_EMPLEADOS];
    int cantidadEmpleados = 0;
    int opcion;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Agregar empleado a tiempo completo\n";
        cout << "2. Agregar empleado a medio tiempo\n";
        cout << "3. Mostrar salarios\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (cantidadEmpleados >= MAX_EMPLEADOS) {
                cout << "No se pueden agregar más empleados.\n";
                continue;
            }
            double salarioMensual;
            cout << "Ingrese el salario mensual: ";
            cin >> salarioMensual;
            empleados[cantidadEmpleados++] = make_shared<EmpleadoTiempoCompleto>(salarioMensual);
        } else if (opcion == 2) {
            if (cantidadEmpleados >= MAX_EMPLEADOS) {
                cout << "No se pueden agregar más empleados.\n";
                continue;
            }
            double salarioPorHora;
            int horasTrabajadas;
            cout << "Ingrese el salario por hora: ";
            cin >> salarioPorHora;
            cout << "Ingrese las horas trabajadas: ";
            cin >> horasTrabajadas;
            empleados[cantidadEmpleados++] = make_shared<EmpleadoMedioTiempo>(salarioPorHora, horasTrabajadas);
        } else if (opcion == 3) {
            for (int i = 0; i < cantidadEmpleados; ++i) {
                cout << "Salario: " << empleados[i]->calcularSalario() << endl;
            }
        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    }

    return 0;
}
