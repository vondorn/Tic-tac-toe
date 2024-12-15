#include "model.h"

void model::setT(int x, int y) {
  if (isValid(x, y)) {
    ts[y][x] = !player ? player1 : player2;
    player = !player;
    // return winnerCheck();
  }
  // return Bad;
  // return No;
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
}

void model::clear() {
  std::swap(player1, player2);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ts[i][j] = No;
    }
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
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!ts[j][i]) {
        setT(i, j);
      }
    }
  }
}

void model::doMove(int x, int y) {
  switch (mode) {
    case ONE:
      setT(x, y);
      computerMove();
    case TWO:
      setT(x, y);
      break;
  }
  winnerCheck();
}

bool model::isValid(int x, int y) { return !ts[y][x]; }
