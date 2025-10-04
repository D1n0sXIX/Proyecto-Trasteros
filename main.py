import Librerias.Conexion as conn
import Librerias.ConsultasTablas as cons

user = input("Introduce el usuario: ")
passw = input("Introduce contraseña: ")
conexion = conn.Conectar(user, passw)

cons.AddCliente(conexion)

conn.Desconectar(None, conexion)