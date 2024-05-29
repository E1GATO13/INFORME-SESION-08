class Animal {
    hacerSonido() {
        throw new Error("Este método debe ser implementado por las subclases");
    }
}

class Perro extends Animal {
    hacerSonido() {
        return "¡Guau!";
    }
}

class Gato extends Animal {
    hacerSonido() {
        return "¡Miau!";
    }
}

class Vaca extends Animal {
    hacerSonido() {
        return "¡Muuu!";
    }
}

function comprobarSonido(animal, sonidoEsperado) {
    if (animal.hacerSonido() === sonidoEsperado) {
        console.log("¡Correcto! El sonido es: " + animal.hacerSonido());
    } else {
        console.log("Incorrecto. El sonido es: " + animal.hacerSonido());
    }
}

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const perro = new Perro();
const gato = new Gato();
const vaca = new Vaca();

function preguntar() {
    console.log("Seleccione un animal para escuchar su sonido:");
    console.log("1. Perro");
    console.log("2. Gato");
    console.log("3. Vaca");
    console.log("4. Salir");

    rl.question('Ingrese una opción: ', (opcion) => {
        if (opcion === '4') {
            rl.close();
            return;
        }

        rl.question('Ingrese el sonido esperado: ', (sonidoEsperado) => {
            switch (opcion) {
                case '1':
                    comprobarSonido(perro, sonidoEsperado);
                    break;
                case '2':
                    comprobarSonido(gato, sonidoEsperado);
                    break;
                case '3':
                    comprobarSonido(vaca, sonidoEsperado);
                    break;
                default:
                    console.log("Opción inválida. Inténtelo de nuevo.");
            }
            preguntar();
        });
    });
}

preguntar();
