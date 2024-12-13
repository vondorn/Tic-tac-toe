#include <QApplication>

#include "controller.h"
#include "model.h"
#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  model m;
  controller c(&m);
  View w(nullptr, &c);
  w.show();
  return a.exec();
}
