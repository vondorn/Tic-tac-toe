#ifndef TTT_H
#define TTT_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "controller.h"
#include "model.h"
#include "ui_ttt.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TTT;
}
QT_END_NAMESPACE

class TTT : public QMainWindow {
  Q_OBJECT
 public:
  TTT() : ui(new Ui::TTT) {
    ui->setupUi(this);
    connect(ui->playButton, &QPushButton::clicked, this, &TTT::startPlay);
    connect(ui->playButton_2, &QPushButton::clicked, this, &TTT::compPlay);
  }

  void startPlay() {
    model* m = new model();
    controller* c = new controller(m);
    View* v = new View(this, c, 0);
    v->show();
  }

  void compPlay() {
    model* m = new model();
    controller* c = new controller(m);
    View* v = new View(this, c, 1);
    v->show();
  }

  ~TTT() { delete ui; }

 private:
  Ui::TTT* ui;
};

#endif  // TTT_H
