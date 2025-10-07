#ifndef GUI_H
#define GUI_H

#include <gtkmm.h>
#include "../Conexion.h"

class AppWindow : public Gtk::Window {
public:
    AppWindow();
    virtual ~AppWindow();

private:
    // Widgets
    Gtk::Box m_VBox{Gtk::ORIENTATION_VERTICAL, 6};
    Gtk::Label m_userLabel{"Usuario:"};
    Gtk::Entry m_userEntry;
    Gtk::Label m_passLabel{"Contraseña:"};
    Gtk::Entry m_passEntry;
    Gtk::Button m_connectButton{"Conectar"};
    Gtk::Button m_checkButton{"Comprobar"};
    Gtk::Button m_closeButton{"Cerrar"};
    Gtk::Label m_statusLabel;

    // Conexión
    ConexionDB* conexion;

    // Handlers
    void on_connect_clicked();
    void on_check_clicked();
    void on_close_clicked();
};

#endif // GUI_H
