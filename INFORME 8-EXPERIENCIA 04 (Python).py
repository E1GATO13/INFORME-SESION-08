class Vehiculo:
    def acelerar(self):
        print("Acelerando el vehículo")

class Coche(Vehiculo):
    def acelerar(self):
        print("Acelerando el coche")

    def encender_luces(self):
        print("Luces del coche encendidas\n")

class Motocicleta(Vehiculo):
    def acelerar(self):
        print("Acelerando la motocicleta")


coche1 = Coche()
coche1.acelerar()
coche1.encender_luces()

moto1 = Motocicleta()
moto1.acelerar()