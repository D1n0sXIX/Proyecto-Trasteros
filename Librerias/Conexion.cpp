#include "Conexion.h"
using namespace std;

// Constructor
ConexionDB::ConexionDB(const string user, const string pass, const string db) {
    this->usuario = user;
    this->contraseña = pass;
    this->baseDatos = db;
    this->conexion = nullptr; // Inicializar el puntero a null
}

// Destructor
ConexionDB::~ConexionDB() {
    cerrarConexion();
}

// Establece la conexión y devuelve true si tuvo éxito
bool ConexionDB::establecerConexion() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        // Usar el prefijo tcp:// para la cadena de conexión
        conexion = driver->connect("tcp://127.0.0.1:3306", this->usuario, this->contraseña);
        conexion->setSchema(this->baseDatos);
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "Error al conectar a la base de datos --> " << e.what() << endl;
        return false;
    }
}
// Comprueba la conexión
bool ConexionDB::comprobarConexion() {
    if (conexion != nullptr && !conexion->isClosed()) {
        return true;
    }
    return false;
}
// Cierra la conexión de forma segura
void ConexionDB::cerrarConexion() {
    if (conexion != nullptr) {
        try {
            conexion->close();
        }
        catch (sql::SQLException& e) {
            cerr << "Error al cerrar la conexión --> " << e.what() << endl;
        }
        delete conexion;
        conexion = nullptr;
    }
}
// Devuelve el puntero a la conexión
sql::Connection* ConexionDB::getConexion() {
    return conexion;
}

// Getters
string ConexionDB::getUsername() {
    return usuario;
}
string ConexionDB::getPassword() {
    return contraseña;
}
string ConexionDB::getDatabase() {
    return baseDatos;
}