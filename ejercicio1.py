from abc import ABC, abstractmethod
from math import pi

# Clase abstracta Figura
class Figura(ABC):
    def __init__(self, nombre):
        self.nombre = nombre

    @abstractmethod
    def calcular_area(self):
        pass

    @abstractmethod
    def dibujar(self):
        pass

# Clase derivada Círculo
class Circulo(Figura):
    def __init__(self, radio):
        super().__init__("Círculo")
        self.radio = radio

    def calcular_area(self):
        return pi * self.radio ** 2

    def dibujar(self):
        print(f"Dibujando un {self.nombre} de radio {self.radio}")

# Clase derivada Rectángulo
class Rectangulo(Figura):
    def __init__(self, base, altura):
        super().__init__("Rectángulo")
        self.base = base
        self.altura = altura

    def calcular_area(self):
        return self.base * self.altura

    def dibujar(self):
        print(f"Dibujando un {self.nombre} de base {self.base} y altura {self.altura}")

# Clase derivada Triángulo
class Triangulo(Figura):
    def __init__(self, base, altura):
        super().__init__("Triángulo")
        self.base = base
        self.altura = altura

    def calcular_area(self):
        return 0.5 * self.base * self.altura

    def dibujar(self):
        print(f"Dibujando un {self.nombre} de base {self.base} y altura {self.altura}")

# Crear instancias de figuras
figuras = [
    Circulo(5),
    Rectangulo(4, 6),
    Triangulo(3, 8)
]

# Llamar a los métodos de cada figura
for figura in figuras:
    figura.dibujar()
    print(f"Área: {figura.calcular_area()}")
    print()