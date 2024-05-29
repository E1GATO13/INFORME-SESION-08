class Figura {
    calcularArea() {
        throw new Error("Este método debe ser implementado por subclases");
    }
}

class Circulo extends Figura {
    constructor(radio) {
        super();
        this.radio = radio;
    }

    calcularArea() {
        return 3.14 * this.radio * this.radio;
    }
}

class Rectangulo extends Figura {
    constructor(ancho, alto) {
        super();
        this.ancho = ancho;
        this.alto = alto;
    }

    calcularArea() {
        return this.ancho * this.alto;
    }
}

class Triangulo extends Figura {
    constructor(base, altura) {
        super();
        this.base = base;
        this.altura = altura;
    }

    calcularArea() {
        return (this.base * this.altura) / 2;
    }
}

class Cuadrado extends Figura {
    constructor(lado) {
        super();
        this.lado = lado;
    }

    calcularArea() {
        return this.lado * this.lado;
    }
}

class Pentagono extends Figura {
    constructor(lado, apotema) {
        super();
        this.lado = lado;
        this.apotema = apotema;
    }

    calcularArea() {
        return (5 * this.lado * this.apotema) / 2;
    }
}

function main() {
    let figura = null;
    const opcion = parseInt(prompt("Seleccione una figura:\n1. Círculo\n2. Rectángulo\n3. Triángulo\n4. Cuadrado\n5. Pentágono\nOpción:"));

    switch (opcion) {
        case 1: {
            const radio = parseFloat(prompt("Ingrese el radio del círculo:"));
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            const ancho = parseFloat(prompt("Ingrese el ancho del rectángulo:"));
            const alto = parseFloat(prompt("Ingrese el alto del rectángulo:"));
            figura = new Rectangulo(ancho, alto);
            break;
        }
        case 3: {
            const base = parseFloat(prompt("Ingrese la base del triángulo:"));
            const altura = parseFloat(prompt("Ingrese la altura del triángulo:"));
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            const lado = parseFloat(prompt("Ingrese el lado del cuadrado:"));
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            const lado = parseFloat(prompt("Ingrese el lado del pentágono:"));
            const apotema = parseFloat(prompt("Ingrese la apotema del pentágono:"));
            figura = new Pentagono(lado, apotema);
            break;
        }
        default:
            alert("Opción no válida.");
            return;
    }

    if (figura) {
        alert("El área de la figura es: " + figura.calcularArea());
    }
}

main();