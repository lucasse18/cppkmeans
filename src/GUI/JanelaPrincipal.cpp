#include "JanelaPrincipal.h"
#include <iostream>

JanelaPrincipal::JanelaPrincipal() : button01("OK"), button02("Close") {
  set_title("Analizar");
  set_size_request(800, 600);
  set_border_width(2);

  add(frame01);
  frame01.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

  button01.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::on_button01_clicked));
  button01.set_size_request(64, 16);
  button_box.pack_start(button01);
  button01.show();

  button02.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::on_button02_clicked));
  button02.set_size_request(64, 16);
  button_box.pack_start(button02);
  button02.show();

  button_box.set_valign(Gtk::ALIGN_END);
  button_box.set_halign(Gtk::ALIGN_END);
  frame01.add(button_box);
  button_box.show();

  frame01.show();

  show();
}

void JanelaPrincipal::on_button01_clicked() {
  std::cout << "Button01 clicked.\n";
}

void JanelaPrincipal::on_button02_clicked() {
  std::cout << "Button02 clicked.\n";
}
