#include "model.h"

Toe model::setT(int x, int y) {
  if (!ts[y][x]) {
    ts[y][x] = cur;
    cur = cur == Tac ? Tic : Tac;
    return winnerCheck();
  } else
    return Bad;
  return No;
}

Toe model::winnerCheck() {
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
  return res;
}

void model::clear() {
  cur = Tac;
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

Toe model::computerMove() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!ts[j][i]) {
        return setT(i, j);
      }
    }
  }
}