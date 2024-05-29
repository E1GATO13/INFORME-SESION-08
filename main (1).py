from abc import ABC, abstractmethod

class Reproductor(ABC):
    """
    Interfaz para un reproductor de audio.
    """

    @abstractmethod
    def reproducir(self):
        """
        Reproduce el audio.
        """
        pass

    @abstractmethod
    def pausar(self):
        """
        Pausa la reproducción del audio.
        """
        pass

    @abstractmethod
    def detener(self):
        """
        Detiene la reproducción del audio.
        """
        pass

class ReproductorMP3(Reproductor):
    """
    Clase que implementa la interfaz Reproductor para archivos MP3.
    """

    def __init__(self, archivo):
        self.archivo = archivo
        self.estado = "Detenido"

    def reproducir(self):
        if self.estado == "Detenido":
            print(f"Reproduciendo {self.archivo}")
            self.estado = "Reproduciendo"
        else:
            print("El audio ya está en reproducción.")

    def pausar(self):
        if self.estado == "Reproduciendo":
            print("Pausando la reproducción.")
            self.estado = "Pausado"
        else:
            print("El audio no está en reproducción.")

    def detener(self):
        if self.estado == "Reproduciendo" or self.estado == "Pausado":
            print("Deteniendo la reproducción.")
            self.estado = "Detenido"
        else:
            print("El audio ya está detenido.")

# Ejemplo de uso
reproductor = ReproductorMP3("cancion.mp3")

reproductor.reproducir()  # Reproduciendo cancion.mp3
reproductor.pausar()  # Pausando la reproducción.
reproductor.detener()  # Deteniendo la reproducción.
reproductor.detener()  # El audio ya está detenido.