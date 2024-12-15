#include "view.h"

#include "./ui_view.h"

View::View(QWidget* parent, controller* c)
    : QWidget(parent), ui(new Ui::View), c_(c) {
  ui->setupUi(this);
  newGame();
}

View::~View() { delete ui; }

void View::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.fillRect(rect(), QBrush("#dee2e6"));
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
  c_->press(event->x(), event->y());
  // if (win == Bad) return;
  update();
  // winCheck();
  // if (computerMode && !win) {
  //   qDebug() << "DD";
  //   win = c_->computerMove();
  //   winCheck();
  // }
}

void View::winCheck() {
  if (win == Tic || win == Tac) {
    win == player1 ? score.first++ : score.second++;
    exitBox();
    win = No;
  } else if (c_->checkFull()) {
    exitBox();
  }
}

void View::exitBox() {
  QMessageBox box;
  box.setText(
      QString("Player 1: %1\tPlayer 2: %2").arg(score.first).arg(score.second));
  QPushButton* newGameButton = new QPushButton("New Game");
  QPushButton* exitButton = new QPushButton("Exit");
  connect(newGameButton, &QPushButton::clicked, this, &View::newGame);
  connect(exitButton, &QPushButton::clicked, this, &View::hide);
  box.addButton(newGameButton, QMessageBox::ActionRole);
  box.addButton(exitButton, QMessageBox::ActionRole);
  box.exec();
}

void View::newGame() {
  // player1 = player1 == Tac ? Tic : Tac;
  c_->clear();
}
