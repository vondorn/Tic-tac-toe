#include "model.h"

void model::setT(int x, int y) {
  if (isValid(x, y)) {
    (*field)(y, x) = !player ? player1 : player2;
    player = !player;
  }
}

Toe model::winnerCheck(Field& f) {
  Toe res = No;
  for (int i = 0; i < 3; ++i) {
    if (f(i, 0) && f(i, 0) == f(i, 1) && f(i, 1) == f(i, 2)) {
      res = f(i, 0);
    }
  }
  for (int j = 0; j < 3; ++j) {
    if (f(0, j) && f(0, j) == f(1, j) && f(1, j) == f(2, j)) {
      res = f(0, j);
    }
  }
  if (((f(0, 0) == f(1, 1) && f(1, 1) == f(2, 2)) ||
       (f(0, 2) == f(1, 1) && f(1, 1) == f(2, 0))) &&
      f(1, 1) != No) {
    res = f(1, 1);
  }
  return res;
}

void model::clear() {
  status = NOTHING;
  std::swap(player1, player2);
  player = player1 == Tac ? 0 : 1;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      (*field)(i, j) = No;
    }
  }
  if (mode == ONE && player) {
    computerMove();
  }
}

bool model::checkFull(Field& f) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!f(i, j)) return 0;
    }
  }
  return 1;
}

void model::computerMove() {
  qDebug() << AI(-1, -1, *field, !player ? player1 : player2);
}

void model::doMove(int x, int y) {
  setT(x, y);
  update();
  if (mode == ONE && !status) {
    computerMove();
    update();
  }
}

bool model::isValid(int x, int y) { return !(*field)(y, x); }

void model::update() {
  Toe check = winnerCheck(*field);
  status = !check ? NOTHING : check == player1 ? WIN_FIRST : WIN_SECOND;
  status = !status && checkFull(*field) ? DRAW : status;
  status == WIN_FIRST ? score1++ : status == WIN_SECOND ? score2++ : 0;
}

Toe model::minimax(int x, int y) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (isValid(x, y)) {
        setT(x, y);
      }
    }
  }
  return winnerCheck(*field);
}

int model::AI(int x, int y, Field field, Toe toe) {
  int res = 0, min = INT32_MAX, temp = 0;
  int xr = -1, yr = -1;
  if (x != -1 && y != -1) {
    field(x, y) = toe;
  }
  field.print();
  Toe win = winnerCheck(field);
  Status status;
  status = !win ? NOTHING : win == player1 ? WIN_FIRST : WIN_SECOND;
  status = !status && checkFull(field) ? DRAW : status;

  if (status == WIN_FIRST) {
    return player ? 0 : 1;
  } else if (status == WIN_SECOND) {
    return player ? 1 : 0;
  } else if (status == DRAW) {
    return 0;
  }
  toe = toe == Tic ? Tac : Tic;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!field(i, j)) {
        temp += AI(i, j, field, toe);
        if (temp < min) {
          min = temp;
          xr = j;
          yr = i;
        }
      }
    }
  }
  return res;
}