import mysql.connector
from mysql.connector import Error

def Conectar(usuario, passw):
    try:
        conexion = mysql.connector.connect(
            host="localhost",
            user=usuario, 
            password=passw,
            database="AppAbuelo"
        )
        if conexion.is_connected():
            print("Conexión establecida a la base de datos\n")
        return conexion
    except Error as e:
        print(f"Error al conectar a MySQL: {e}\n")
        return None


def ComprobarConexion(conexion):
    if conexion is not None and conexion.is_connected():
        return True
    return False


def Desconectar(cursor, conexion):
    if cursor is not None:
        cursor.close()
        print("Cursor cerrado\n")
    if conexion is not None:
        conexion.close()
        print("Conexion cerrada\n")

    
