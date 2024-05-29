// Interfaz Reproductor
function Reproductor() {}

Reproductor.prototype.reproducir = function() {
    throw new Error('El método reproducir() debe ser implementado');
};

Reproductor.prototype.pausar = function() {
    throw new Error('El método pausar() debe ser implementado');
};

Reproductor.prototype.detener = function() {
    throw new Error('El método detener() debe ser implementado');
};

// Clase ReproductorMP3 que implementa la interfaz Reproductor
function ReproductorMP3(archivo) {
    this.archivo = archivo;
    this.estado = 'Detenido';
}

ReproductorMP3.prototype = new Reproductor();
ReproductorMP3.prototype.constructor = ReproductorMP3;

ReproductorMP3.prototype.reproducir = function() {
    if (this.estado === 'Detenido') {
        print('Reproduciendo ' + this.archivo);
        this.estado = 'Reproduciendo';
    } else {
        print('El audio ya está en reproducción.');
    }
};

ReproductorMP3.prototype.pausar = function() {
    if (this.estado === 'Reproduciendo') {
        print('Pausando la reproducción.');
        this.estado = 'Pausado';
    } else {
        print('El audio no está en reproducción.');
    }
};

ReproductorMP3.prototype.detener = function() {
    if (this.estado === 'Reproduciendo' || this.estado === 'Pausado') {
        print('Deteniendo la reproducción.');
        this.estado = 'Detenido';
    } else {
        print('El audio ya está detenido.');
    }
};

// Ejemplo de uso
var reproductor = new ReproductorMP3('cancion.mp3');

reproductor.reproducir(); // Reproduciendo cancion.mp3
reproductor.pausar(); // Pausando la reproducción.
reproductor.detener(); // Deteniendo la reproducción.
reproductor.detener(); // El audio ya está detenido.