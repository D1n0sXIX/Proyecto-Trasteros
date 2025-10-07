#include <mysql_driver.h>
#include <mysql_connection.h>
#include <iostream>

using namespace std;

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    string nombre = "";
    string password = "";
    cout << "Ingrese su nombre de usuario y contraseña: ";
    cin >> nombre;
    cin >> password;

    // Conexión al servidor MySQL
    driver = sql::mysql::get_mysql_driver_instance();
    
    con = driver->connect("tcp://127.0.0.1:3306", nombre, password);

    con->setSchema("AppAbuelo");

    std::cout << "Conexión exitosa a la base de datos MySQL" << std::endl;

    delete con;
    return 0;
}
