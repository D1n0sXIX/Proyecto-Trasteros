# ProyectoTrasteros
Desarrollo de una aplicacion en Python para administrar un negocio de trasteros

Base de Datos:
    Tabla Clientes:
        - Id
        - Nombre
        - Apellidos
        - DNI
        - Telefono
        - Direccion
        - Localidad
        - Provincia
        - Codigo Postal
        - Trastero Asignado
        - Comentarios extra
        - Id Contrato
    Tabla Trastero
        - Num Trastero
        - Disponibilidad
        - Precio
    Tabla Pagos
        - Fecha del contrato
        - Renta a pagar
        - Metodo de pago
        - pago realizado (bool)

Cliente puede tener varios Pagos 1:n
Cliente Puede tener varios trasteros 1:n

# Funciones Necesarias
#1 Conexion con la base de datos
    # Conectar  --> CHECK
    # Comprobar conexion --> CHECK
    # Cortar conexion --> CHECK

#2 Consultas a la Tabla
    # Añadir, modificar, ver, eliminar


#3 Ver pagos de cada mes
    # Gente que ha pagado
    # Gente que no ha pagado
    # Ver fechas de apgo con n de trastero
    # Ver trasteros Libres
    # Ver trateros ocupados
#4 Opciones economicas
    # importe total cobrado del mes
    # Ver cobros de ese mes
    # Importe medio de renta de trasteros = Renta Total cobrada / Num trasteros alquilados

#5 UX
    