#include <gtkmm.h>
#include "Librerias/GUI/GUI.h"

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "org.proyecto.trasteros");
    AppWindow window;
    return app->run(window);
}
