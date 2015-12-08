#include <glibmm/refptr.h>
#include <gtkmm/application.h>
#include "PacoteGUI/JanelaPrincipal.h"

using Gtk::Application;

int main(int argc, char *argv[]) {

  Glib::RefPtr<Application> app = Gtk::Application::create(argc, argv);

  JanelaPrincipal jp;

  return app->run(jp);
}
