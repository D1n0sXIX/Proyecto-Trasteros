import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout

class Interfaz(QWidget):
    def __init__(self):
        super().__init__()

        # Titulo de la ventana
        self.setWindowTitle('Mi Interfaz con Botones')

        # Configuración de la ventana
        self.setGeometry(100, 100, 400, 300)

        # Crear el layout (diseño de los elementos dentro de la ventana)
        layout = QVBoxLayout()

        # Crear botones
        self.boton1 = QPushButton('Botón 1')
        self.boton2 = QPushButton('Botón 2')

        # Conectar los botones con las acciones
        self.boton1.clicked.connect(self.accion_boton1)
        self.boton2.clicked.connect(self.accion_boton2)

        # Añadir los botones al layout
        layout.addWidget(self.boton1)
        layout.addWidget(self.boton2)

        # Establecer el layout de la ventana
        self.setLayout(layout)

    def accion_boton1(self):
        print("Has presionado el Botón 1")

    def accion_boton2(self):
        print("Has presionado el Botón 2")

# Iniciar la aplicación PyQt
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ventana = Interfaz()
    ventana.show()
    sys.exit(app.exec_())
