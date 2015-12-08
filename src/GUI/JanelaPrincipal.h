#ifndef CPPKMEANS_JANELAPRINCIPAL_H
#define CPPKMEANS_JANELAPRINCIPAL_H


#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/box.h>

using Gtk::Window;
using Gtk::Button;
using Gtk::Frame;
using Gtk::Box;

class JanelaPrincipal : public Window{

public:
  JanelaPrincipal();
  virtual ~JanelaPrincipal() { }

protected:
  //Elementos
  Frame frame01;
  Button button01;
  Button button02;
  Box button_box;

  //Handlers
  void on_button01_clicked();
  void on_button02_clicked();

};


#endif //CPPKMEANS_JANELAPRINCIPAL_H
