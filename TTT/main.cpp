#include <QApplication>

// #include "controller.h"
// #include "model.h"
#include "ttt.h"
// #include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  TTT t;
  t.show();
  return a.exec();
}
