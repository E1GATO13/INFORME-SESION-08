class Animal:
    def hacer_sonido(self):
        raise NotImplementedError

class Perro(Animal):
    def hacer_sonido(self):
        return "¡Guau!"

class Gato(Animal):
    def hacer_sonido(self):
        return "¡Miau!"

class Vaca(Animal):
    def hacer_sonido(self):
        return "¡Muuu!"

def comprobar_sonido(animal, sonido_esperado):
    if animal.hacer_sonido() == sonido_esperado:
        print(f"¡Correcto! El sonido es: {animal.hacer_sonido()}")
    else:
        print(f"Incorrecto. El sonido es: {animal.hacer_sonido()}")

def main():
    perro = Perro()
    gato = Gato()
    vaca = Vaca()

    while True:
        print("Seleccione un animal para escuchar su sonido:")
        print("1. Perro")
        print("2. Gato")
        print("3. Vaca")
        print("4. Salir")
        opcion = int(input())

        if opcion == 4:
            break

        sonido_esperado = input("Ingrese el sonido esperado: ")

        if opcion == 1:
            comprobar_sonido(perro, sonido_esperado)
        elif opcion == 2:
            comprobar_sonido(gato, sonido_esperado)
        elif opcion == 3:
            comprobar_sonido(vaca, sonido_esperado)
        else:
            print("Opción inválida. Inténtelo de nuevo.")

if __name__ == "__main__":
    main()
