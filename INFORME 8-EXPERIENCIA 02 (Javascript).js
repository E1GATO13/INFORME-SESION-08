class Forma {
    constructor() {
        if (this.constructor === Forma) {
            throw new Error("No puedes instanciar un objeto de la clase abstracta 'Forma'.");
        }
    }
    calcularPerimetro() {
        throw new Error("El método 'calcularPerimetro' debe ser implementado por las clases derivadas.");
    }
}

class Circulo extends Forma {
    constructor(radio) {
        super();
        this.radio = radio;
    }

    calcularPerimetro() {
        return 2 * Math.PI * this.radio;
    }
}

class Rectangulo extends Forma {
    constructor(base, altura) {
        super();
        this.base = base;
        this.altura = altura;
    }

    calcularPerimetro() {
        return 2 * (this.base + this.altura);
    }
}
class Triangulo extends Forma {
    constructor(lado1, lado2, lado3) {
        super();
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    calcularPerimetro() {
        return this.lado1 + this.lado2 + this.lado3;
    }
}
function main() {
    let opcion = prompt("Seleccione una forma geométrica (círculo, rectángulo, triángulo):").toLowerCase();
    let forma;

    switch (opcion) {
        case "círculo":
            let radioCirculo = parseFloat(prompt("Ingrese el radio del círculo:"));
            forma = new Circulo(radioCirculo);
            break;
        case "rectángulo":
            let baseRectangulo = parseFloat(prompt("Ingrese la base del rectángulo:"));
            let alturaRectangulo = parseFloat(prompt("Ingrese la altura del rectángulo:"));
            forma = new Rectangulo(baseRectangulo, alturaRectangulo);
            break;
        case "triángulo":
            let lado1Triangulo = parseFloat(prompt("Ingrese el lado 1 del triángulo:"));
            let lado2Triangulo = parseFloat(prompt("Ingrese el lado 2 del triángulo:"));
            let lado3Triangulo = parseFloat(prompt("Ingrese el lado 3 del triángulo:"));
            forma = new Triangulo(lado1Triangulo, lado2Triangulo, lado3Triangulo);
            break;
        default:
            console.log("Forma no válida.");
            return;
    }
    console.log(`El perímetro de la forma seleccionada es: ${forma.calcularPerimetro()}`);
}
// Ejecutar el programa
main();
