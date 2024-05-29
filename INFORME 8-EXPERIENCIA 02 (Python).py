class Forma:
    def calcular_perimetro(self):
        pass

class Circulo(Forma):
    PI = 3.1416

    def __init__(self, radio):
        self.radio = radio

    def calcular_perimetro(self):
        return 2 * Circulo.PI * self.radio

class Rectangulo(Forma):
    def __init__(self, largo, ancho):
        self.largo = largo
        self.ancho = ancho

    def calcular_perimetro(self):
        return 2 * (self.largo + self.ancho)

class Triangulo(Forma):
    def __init__(self, lado1, lado2, lado3):
        self.lado1 = lado1
        self.lado2 = lado2
        self.lado3 = lado3

    def calcular_perimetro(self):
        return self.lado1 + self.lado2 + self.lado3

def crear_forma(seleccion):
    if seleccion == 1:
        radio = float(input("Ingrese el radio del círculo: "))
        return Circulo(radio)
    elif seleccion == 2:
        largo = float(input("Ingrese el largo del rectángulo: "))
        ancho = float(input("Ingrese el ancho del rectángulo: "))
        return Rectangulo(largo, ancho)
    elif seleccion == 3:
        lado1 = float(input("Ingrese el primer lado del triángulo: "))
        lado2 = float(input("Ingrese el segundo lado del triángulo: "))
        lado3 = float(input("Ingrese el tercer lado del triángulo: "))
        return Triangulo(lado1, lado2, lado3)
    else:
        print("Selección inválida.")
        return None

def main():
    continuar = 's'
    while continuar.lower() == 's':
        opc_valida = False

        while not opc_valida:
            print("Seleccione una forma para calcular su perímetro:")
            print("1. Círculo")
            print("2. Rectángulo")
            print("3. Triángulo")
            try:
                opc = int(input("Ingrese su selección: "))
                if opc >= 1 and opc <= 3:
                    opc_valida = True
                else:
                    print("Por favor, intente de nuevo.")
            except ValueError:
                print("Por favor, ingrese un número válido.")

        forma = crear_forma(opc)
    
        if forma:
            print("El perímetro de la forma seleccionada es:", forma.calcular_perimetro())
            continuar = input("¿Desea calcular el perímetro de otra forma? (s/n): ")
        else:
            continuar = 'n'

if __name__ == "__main__":
    main()
