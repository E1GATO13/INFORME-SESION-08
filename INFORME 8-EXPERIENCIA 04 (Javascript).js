class Vehiculo {
    acelerar() {
        console.log("Acelerando el vehículo");
    }
}

class Coche extends Vehiculo {
    acelerar() {
        console.log("Acelerando el coche");
    }

    encenderLuces() {
        console.log("Luces del coche encendidas \n");
    }
}

class Motocicleta extends Vehiculo {
    acelerar() {
        console.log("Acelerando la motocicleta");
    }
}

let coche1 = new Coche();
coche1.acelerar();
coche1.encenderLuces();

let moto1 = new Motocicleta();
moto1.acelerar();