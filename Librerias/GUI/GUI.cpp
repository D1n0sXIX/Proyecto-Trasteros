#include "GUI.h"
#include <iostream>

AppWindow::AppWindow()
: conexion(nullptr)
{
    set_title("Gestión BD");
    set_default_size(400,200);

    add(m_VBox);

    m_userEntry.set_placeholder_text("Introduce tu usuario");
    m_passEntry.set_placeholder_text("Introduce tu contraseña");
    m_passEntry.set_visibility(false);

    // Poner etiquetas encima de cada entrada
    m_VBox.pack_start(m_userLabel, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_userEntry, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_passLabel, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_passEntry, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_connectButton, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_checkButton, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_closeButton, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_statusLabel, Gtk::PACK_SHRINK);

    m_connectButton.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_connect_clicked));
    m_checkButton.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_check_clicked));
    m_closeButton.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_close_clicked));

    // Dejar los botones Comprobar y Cerrar siempre habilitados
    m_checkButton.set_sensitive(true);
    m_closeButton.set_sensitive(true);

    // --- Estilos CSS ---
    auto provider = Gtk::CssProvider::create();
    try {
        provider->load_from_data(
            "button#connect { background: #4CAF50; color: white; }"
            "button#check { background: #2196F3; color: white; }"
            "button#close { background: #f44336; color: white; }"
            "label#status { color: #333333; font-weight: bold; }"
        );
        auto screen = Gdk::Screen::get_default();
        if (screen) {
            Gtk::StyleContext::add_provider_for_screen(screen, provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
        }
    } catch (const Gtk::CssProviderError& e) {
        std::cerr << "No se pudo cargar CSS: " << e.what() << std::endl;
    }

    // Asignar nombres a widgets para que el CSS los afecte
    m_connectButton.set_name("connect");
    m_checkButton.set_name("check");
    m_closeButton.set_name("close");
    m_statusLabel.set_name("status");

    show_all_children();
}

AppWindow::~AppWindow(){
    if (conexion) {
        delete conexion;
        conexion = nullptr;
    }
}

void AppWindow::on_connect_clicked(){
    std::string user = m_userEntry.get_text();
    std::string pass = m_passEntry.get_text();
    std::string db = "AppAbuelo";

    if (conexion) {
        m_statusLabel.set_text("Ya existe una conexión");
        return;
    }

    conexion = new ConexionDB(user, pass, db);
    if (conexion->establecerConexion()){
        m_statusLabel.set_text("Conectado como: " + conexion->getUsername());
        m_checkButton.set_sensitive(true);
        m_closeButton.set_sensitive(true);
    }
    else{
        m_statusLabel.set_text("No se pudo conectar. Revisa credenciales o servidor.");
        delete conexion;
        conexion = nullptr;
    }
}

void AppWindow::on_check_clicked(){
    if (!conexion) {
        m_statusLabel.set_text("No hay conexión establecida");
        return;
    }
    if (conexion->comprobarConexion()){
        m_statusLabel.set_text("La conexión está activa");
    } else {
        m_statusLabel.set_text("La conexión no está activa");
    }
}

void AppWindow::on_close_clicked(){
    if (!conexion) {
        m_statusLabel.set_text("No hay conexión que cerrar");
        return;
    }
    conexion->cerrarConexion();
    delete conexion;
    conexion = nullptr;
    m_statusLabel.set_text("Conexión cerrada");
}
