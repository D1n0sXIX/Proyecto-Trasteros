#ifndef CONEXIONES_H
#define CONEXIONES_H

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <iostream>
#include <string>

using namespace std;

class ConexionDB {
private:
    sql::Connection* conexion; // Puntero a la conexión
    string usuario;
    string contraseña;
    string baseDatos;

public:
    // Constructor
    ConexionDB(const string user, const string pass, const string db);

    // Destructor
    ~ConexionDB();

    // Metodos
    // Establece la conexión y devuelve true si tuvo éxito
    bool establecerConexion();
    // Comprueba la conexión
    bool comprobarConexion();
    // Cierra la conexión de forma segura
    void cerrarConexion();
    // Devuelve el puntero a la conexión
    sql::Connection* getConexion();

    //Getters
    string getUsername();
    string getPassword();
    string getDatabase();
};

#endif // CONEXIONES_H
