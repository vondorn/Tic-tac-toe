#ifndef VIEW_H
#define VIEW_H

#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QWidget {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr, controller *c = nullptr, bool mode = 0);
  ~View();

  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void exitBox();
  void newGame();
  void winCheck();

  controller *c_;

 private:
  Ui::View *ui;
  Toe win = No, player1 = Tic;
  bool computerMode = 0;
  std::pair<int, int> score = {0, 0};
};
#endif  // VIEW_H
