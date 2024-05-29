class Empleado:
    def calcular_salario(self):
        raise NotImplementedError("Debe implementar este método")

class EmpleadoTiempoCompleto(Empleado):
    def __init__(self, salario_mensual):
        self.salario_mensual = salario_mensual

    def calcular_salario(self):
        return self.salario_mensual

class EmpleadoMedioTiempo(Empleado):
    def __init__(self, salario_por_hora, horas_trabajadas):
        self.salario_por_hora = salario_por_hora
        self.horas_trabajadas = horas_trabajadas

    def calcular_salario(self):
        return self.salario_por_hora * self.horas_trabajadas

def main():
    empleados = []
    
    while True:
        print("Menu:")
        print("1. Agregar empleado a tiempo completo")
        print("2. Agregar empleado a medio tiempo")
        print("3. Mostrar salarios")
        print("4. Salir")
        opcion = int(input("Seleccione una opcion: "))

        if opcion == 1:
            salario_mensual = float(input("Ingrese el salario mensual: "))
            empleados.append(EmpleadoTiempoCompleto(salario_mensual))
        elif opcion == 2:
            salario_por_hora = float(input("Ingrese el salario por hora: "))
            horas_trabajadas = int(input("Ingrese las horas trabajadas: "))
            empleados.append(EmpleadoMedioTiempo(salario_por_hora, horas_trabajadas))
        elif opcion == 3:
            for empleado in empleados:
                print(f"Salario: {empleado.calcular_salario()}")
        elif opcion == 4:
            break
        else:
            print("Opcion invalida, intente de nuevo.")

if __name__ == "__main__":
    main()
