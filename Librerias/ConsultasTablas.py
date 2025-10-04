import mysql.connector
from mysql.connector import Error
import Librerias.Conexion as conn

def AddCliente(conexion):
    if not conn.ComprobarConexion(conexion):
        print("Se perdió la conexión")
        return None
    
    print("Introduce los datos del cliente: ")

    # Solicitar los datos del cliente
    nombre = (input("Nombre: "))
    apellidos = (input("Apellido: "))
    dni = (input("DNI:) "))
    telefono = int(input("Teleono: "))
    direccion = (input("Dirección: "))
    localidad = (input("Localidad: "))
    provincia = (input("Provincia: "))
    codigoPostal = int(input("Codigo Postal: "))
    compr = input("Quieres añadir comentarios extra? (S/N): ")
    if(compr == "S" or compr == "s"):
        comentariosExtra = input("Introduce el comentario:")
    else:
        comentariosExtra = ""
    

    # Crear el cursor para ejecutar la consulta
    # Comentado para testing
    #cursor = conexion.cursor()

    # Preparar la consulta SQL para insertar el cliente
    try:
        insert_query = """
        INSERT INTO Clientes (NombreApellidos, DNI, Telefono, Direccion, Localidad, 
                              Provincia, CodigoPostal, TrasteroAsignado, ComentariosExtra, IdContrato)
        VALUES (%s, %s, %s, %d, %s, %s, %s, %d)
        """
        
        # Ejecutar la consulta con los datos del cliente
        cursor.execute(insert_query, (nombre, apellidos, dni, telefono, direccion, localidad,
                                      provincia, codigoPosta))

        # Confirmar la inserción
        conexion.commit()

        print("Cliente añadido exitosamente.")
    
    except Error as e:
        print(f"Error al insertar el cliente: {e}")
        conexion.rollback()

    finally:
        # Cerrar el cursor
        cursor.close()
