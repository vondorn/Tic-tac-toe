#ifndef VIEW_H
#define VIEW_H

#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
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
  View(QWidget *parent = nullptr, controller *c = nullptr);
  ~View();

  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void exitBox();

 private:
  Ui::View *ui;
  controller *c_;
  Toe win = No;
};
#endif  // VIEW_H
