#include "model.h"

void model::setT(int x, int y) {
  if (isValid(x, y)) {
    ts[y][x] = !player ? player1 : player2;
    player = !player;
    winnerCheck();
  }
}

void model::winnerCheck() {
  Toe res = No;
  for (int i = 0; i < 3; ++i) {
    if (ts[i][0] && ts[i][0] == ts[i][1] && ts[i][1] == ts[i][2]) {
      res = ts[i][0];
    }
  }
  for (int j = 0; j < 3; ++j) {
    if (ts[0][j] && ts[0][j] == ts[1][j] && ts[1][j] == ts[2][j]) {
      res = ts[0][j];
    }
  }
  if (((ts[0][0] == ts[1][1] && ts[1][1] == ts[2][2]) ||
       (ts[0][2] == ts[1][1] && ts[1][1] == ts[2][0])) &&
      ts[1][1] != No) {
    res = ts[1][1];
  }
  status = !res ? NOTHING : res == player1 ? WIN_FIRST : WIN_SECOND;
  status = !status && checkFull() ? DRAW : status;
  updateScore();
}

void model::clear() {
  status = NOTHING;
  std::swap(player1, player2);
  player = player1 == Tac ? 0 : 1;
  qDebug() << player1 << "\t" << player2 << "\t\t" << player;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ts[i][j] = No;
    }
  }
  if (mode == ONE && player) {
    computerMove();
  }
}

bool model::checkFull() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!ts[i][j]) return 0;
    }
  }
  return 1;
}

void model::computerMove() {
  int x, y;
  do {
    x = rand() % 3;
    y = rand() % 3;
  } while (!isValid(x, y));
  setT(x, y);
}

void model::doMove(int x, int y) {
  setT(x, y);

  if (mode == ONE && !status) {
    computerMove();
  }
}

bool model::isValid(int x, int y) { return !ts[y][x]; }

void model::updateScore() {
  status == WIN_FIRST ? score1++ : status == WIN_SECOND ? score2++ : 0;
}
