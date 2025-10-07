#include <mysql_driver.h>
#include <mysql_connection.h>
#include <iostream>
#include <string>
#include "Librerias/Conexion.h"
using namespace std;

int main() {
    string user ="";
    string pass ="";
    string db ="AppAbuelo";
    cout << "Introduce el usuario y contraseña de la base de datos: ";
    cin >> user;
    cin >> pass;
    ConexionDB conexion(user, pass, db);

    if (conexion.establecerConexion()){
        cout << "El usuario " << conexion.getUsername() << " ha establecido conexion con " << conexion.getDatabase() << endl; 
    }
    else{
        cout << "No se ha podido establecer la conexion" << endl;
        return 0;
    }


    cout << "Escoge una de las opciones: " << endl;
    cout << "1. Comprobar conexion" << endl;
    cout << "2. Cerrar conexion" << endl;
    int opcion = 0;
    do{
        cout<<": ";
        cin >> opcion;
        switch (opcion){
        case 1:
            if (conexion.comprobarConexion()){
                cout << "La conexion esta activa" << endl;
            }
            else{
                cout << "La conexion no esta activa" << endl;
            }
        break;
        
        case 2:
            conexion.cerrarConexion();
            if (!conexion.comprobarConexion()){
                cout << "La conexion se ha cerrado correctamente" << endl;
            }
            else{
                cout << "La conexion no se ha cerrado correctamente" << endl;
            }
        break;

        default:
            cout << "Opcion no valida\nPrueba de nuevo" << endl;
            break;
        }
    }while(opcion != 2 );
    
    
    return 0;
}
