// Clase abstracta Figura
function Figura(nombre) {
    this.nombre = nombre;
}

Figura.prototype.calcularArea = function() {
    throw new Error("Método calcularArea() debe ser implementado");
}

Figura.prototype.dibujar = function() {
    throw new Error("Método dibujar() debe ser implementado");
}

// Clase derivada Círculo
function Circulo(radio) {
    Figura.call(this, "Círculo");
    this.radio = radio;
}

Circulo.prototype = Object.create(Figura.prototype);
Circulo.prototype.constructor = Circulo;

Circulo.prototype.calcularArea = function() {
    return Math.PI * this.radio * this.radio;
}

Circulo.prototype.dibujar = function() {
    print("Dibujando un " + this.nombre + " de radio " + this.radio);
}

// Clase derivada Rectángulo
function Rectangulo(base, altura) {
    Figura.call(this, "Rectángulo");
    this.base = base;
    this.altura = altura;
}

Rectangulo.prototype = Object.create(Figura.prototype);
Rectangulo.prototype.constructor = Rectangulo;

Rectangulo.prototype.calcularArea = function() {
    return this.base * this.altura;
}

Rectangulo.prototype.dibujar = function() {
    print("Dibujando un " + this.nombre + " de base " + this.base + " y altura " + this.altura);
}

// Clase derivada Triángulo
function Triangulo(base, altura) {
    Figura.call(this, "Triángulo");
    this.base = base;
    this.altura = altura;
}

Triangulo.prototype = Object.create(Figura.prototype);
Triangulo.prototype.constructor = Triangulo;

Triangulo.prototype.calcularArea = function() {
    return 0.5 * this.base * this.altura;
}

Triangulo.prototype.dibujar = function() {
    print("Dibujando un " + this.nombre + " de base " + this.base + " y altura " + this.altura);
}

// Crear instancias de figuras
var figuras = [
    new Circulo(5),
    new Rectangulo(4, 6),
    new Triangulo(3, 8)
];

// Llamar a los métodos de cada figura
for (var i = 0; i < figuras.length; i++) {
    figuras[i].dibujar();
    print("Área: " + figuras[i].calcularArea());
    print();
}