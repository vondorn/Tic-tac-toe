#include "view.h"

#include "./ui_view.h"

View::View(QWidget* parent, controller* c)
    : QWidget(parent), ui(new Ui::View), c_(c) {
  ui->setupUi(this);
}

View::~View() { delete ui; }

void View::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  int cellSize = size().height() / 3;
  Toe** ts = c_->getCells();
  qreal cornerRadius = 20;
  painter.setPen(QPen(QBrush("#343a40"), 10));
  painter.drawLine(cellSize, 0, cellSize, cellSize * 3);
  painter.drawLine(2 * cellSize, 0, 2 * cellSize, cellSize * 3);
  painter.drawLine(0, cellSize, cellSize * 3, cellSize);
  painter.drawLine(0, 2 * cellSize, cellSize * 3, 2 * cellSize);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      // painter.setBrush(QBrush("#343a40"));
      // painter.setPen(QPen(QColor(0, 0, 0), 0));
      // QRect rect(j * cellSize, i * cellSize, cellSize, cellSize);
      // painter.drawRoundedRect(rect, cornerRadius, cornerRadius);

      if (ts[i][j] == Tic) {
        painter.setBrush(Qt::NoBrush);  // Без заливки
        painter.setPen(
            QPen(QColor(0, 0, 255), 20));  // Синий цвет и ширина линии 10
        painter.drawEllipse(j * cellSize + 20, i * cellSize + 20,
                            cellSize / 1.25f, cellSize / 1.25f);
      } else if (ts[i][j] == Tac) {
        painter.setPen(QPen(QColor(255, 0, 0), 20));
        painter.drawLine(
            j * cellSize + cellSize / 8, i * cellSize + cellSize / 8,
            j * cellSize + 7 * cellSize / 8, i * cellSize + 7 * cellSize / 8);
        painter.drawLine(
            j * cellSize + cellSize / 8, i * cellSize + 7 * cellSize / 8,
            j * cellSize + 7 * cellSize / 8, i * cellSize + cellSize / 8);
      }
    }
  }
}

void View::mousePressEvent(QMouseEvent* event) {
  win = c_->press(event->x(), event->y());
  update();
  if (win) exitBox();
}

void View::exitBox() {
  QMessageBox box;
  box.setText(win == Tic ? "Player 2 wins" : "Player 1 wins");
  QPushButton* exitButton = new QPushButton("Exit");
  connect(exitButton, &QPushButton::clicked, this, close());
  box.addButton(exitButton, QMessageBox::ActionRole);
  box.exec();
}

void View::newGame() {
  
}