class Empleado {
    calcularSalario() {}
}

class EmpleadoTiempoCompleto extends Empleado {
    constructor(salarioMensual) {
        super();
        this.salarioMensual = salarioMensual;
    }

    calcularSalario() {
        return this.salarioMensual;
    }
}

class EmpleadoMedioTiempo extends Empleado {
    constructor(salarioPorHora, horasTrabajadas) {
        super();
        this.salarioPorHora = salarioPorHora;
        this.horasTrabajadas = horasTrabajadas;
    }

    calcularSalario() {
        return this.salarioPorHora * this.horasTrabajadas;
    }
}

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const empleados = [];

rl.on('line', (input) => {
    switch (parseInt(input)) {
        case 1:
            console.log("Ingrese el salario mensual: ");
            break;
        case 2:
            console.log("Ingrese el salario por hora: ");
            break;
        case 3:
            for (const empleado of empleados) {
                console.log("Salario: " + empleado.calcularSalario());
            }
            break;
        case 4:
            rl.close();
            break;
        default:
            console.log("Opcion invalida, intente de nuevo.");
    }
});

let opcion = 0;

function handleInput(data) {
    if (opcion === 1) {
        const salarioMensual = parseFloat(data);
        empleados.push(new EmpleadoTiempoCompleto(salarioMensual));
    } else if (opcion === 2) {
        const salarioPorHora = parseFloat(data);
        console.log("Ingrese las horas trabajadas: ");
    } else if (opcion === 3) {
        const horasTrabajadas = parseInt(data);
        empleados.push(new EmpleadoMedioTiempo(salarioPorHora, horasTrabajadas));
    }
    rl.prompt();
}

rl.on('line', handleInput);

console.log("Menu:");
console.log("1. Agregar empleado a tiempo completo");
console.log("2. Agregar empleado a medio tiempo");
console.log("3. Mostrar salarios");
console.log("4. Salir");
console.log("Seleccione una opcion: ");
rl.prompt();
