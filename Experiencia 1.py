class Figura:
    def calcular_area(self):
        pass

class Circulo(Figura):
    def __init__(self, radio):
        self.radio = radio

    def calcular_area(self):
        return 3.14 * self.radio * self.radio

class Rectangulo(Figura):
    def __init__(self, ancho, alto):
        self.ancho = ancho
        self.alto = alto

    def calcular_area(self):
        return self.ancho * self.alto

class Triangulo(Figura):
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura

    def calcular_area(self):
        return (self.base * self.altura) / 2

class Cuadrado(Figura):
    def __init__(self, lado):
        self.lado = lado

    def calcular_area(self):
        return self.lado * self.lado

class Pentagono(Figura):
    def __init__(self, lado, apotema):
        self.lado = lado
        self.apotema = apotema

    def calcular_area(self):
        return (5 * self.lado * self.apotema) / 2

def main():
    opcion = int(input("Seleccione una figura:\n1. Circulo\n2. Rectangulo\n3. Triangulo\n4. Cuadrado\n5. Pentagono\nOpcion: "))

    if opcion == 1:
        radio = float(input("Ingrese el radio del circulo: "))
        figura = Circulo(radio)
    elif opcion == 2:
        ancho = float(input("Ingrese el ancho del rectangulo: "))
        alto = float(input("Ingrese el alto del rectangulo: "))
        figura = Rectangulo(ancho, alto)
    elif opcion == 3:
        base = float(input("Ingrese la base del triangulo: "))
        altura = float(input("Ingrese la altura del triangulo: "))
        figura = Triangulo(base, altura)
    elif opcion == 4:
        lado = float(input("Ingrese el lado del cuadrado: "))
        figura = Cuadrado(lado)
    elif opcion == 5:
        lado = float(input("Ingrese el lado del pentagono: "))
        apotema = float(input("Ingrese la apotema del pentagono: "))
        figura = Pentagono(lado, apotema)
    else:
        print("Opcion no valida.")
        return

    print("El area de la figura es: ", figura.calcular_area())

if __name__ == "__main__":
    main()
