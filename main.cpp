#include <iostream>
#include <string>

using namespace std;

// Interfaz Reproductor
class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual ~Reproductor() {} // Destructor virtual
};

// Clase ReproductorMP3 que implementa la interfaz Reproductor
class ReproductorMP3 : public Reproductor {
private:
    string archivo;
    string estado;

public:
    ReproductorMP3(const string& archivo) : archivo(archivo), estado("Detenido") {}

    void reproducir() override {
        if (estado == "Detenido") {
            cout << "Reproduciendo " << archivo << endl;
            estado = "Reproduciendo";
        } else {
            cout << "El audio ya está en reproducción." << endl;
        }
    }

    void pausar() override {
        if (estado == "Reproduciendo") {
            cout << "Pausando la reproducción." << endl;
            estado = "Pausado";
        } else {
            cout << "El audio no está en reproducción." << endl;
        }
    }

    void detener() override {
        if (estado == "Reproduciendo" || estado == "Pausado") {
            cout << "Deteniendo la reproducción." << endl;
            estado = "Detenido";
        } else {
            cout << "El audio ya está detenido." << endl;
        }
    }
};

int main() {
    ReproductorMP3 reproductor("cancion.mp3");

    reproductor.reproducir(); // Reproduciendo cancion.mp3
    reproductor.pausar(); // Pausando la reproducción.
    reproductor.detener(); // Deteniendo la reproducción.
    reproductor.detener(); // El audio ya está detenido.

    return 0;
}