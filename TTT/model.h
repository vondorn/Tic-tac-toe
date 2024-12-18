#ifndef MODEL_H
#define MODEL_H

#include <qdebug.h>

#include <array>
#include <iostream>
#include <random>
#include <vector>

typedef enum { No, Tic, Tac, Bad } Toe;
typedef enum { ONE, TWO } Mode;
typedef enum { NOTHING, DRAW, WIN_FIRST, WIN_SECOND } Status;

class Field {
 public:
  Field() {
    ts = new Toe*[3];
    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }
  }
  Field(const Field& other) {
    ts = new Toe*[3];
    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ts[i][j] = other.ts[i][j];
      }
    }
  }
  Field& operator=(const Field& other) {
    if (this == &other) {
      return *this;
    }

    for (int i = 0; i < 3; ++i) {
      delete[] ts[i];
    }
    delete[] ts;

    ts = new Toe*[3];
    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ts[i][j] = other.ts[i][j];
      }
    }

    return *this;
  }
  ~Field() {
    for (int i = 0; i < 3; ++i) {
      delete[] ts[i];
    }
    delete[] ts;
  }
  Toe& operator()(int x, int y) { return ts[y][x]; }

 private:
  Toe** ts = nullptr;
};

class model {
 public:
  model(Mode m) : mode(m), field(new Field) {}
  Field getField() { return *field; }
  void setT(int x, int y);
  Toe winnerCheck();
  void clear();
  bool checkFull();
  void computerMove();
  void doMove(int x, int y);
  bool isValid(int x, int y);
  Status getStatus() { return status; }
  void update();
  int getScore1() { return score1; }
  int getScore2() { return score2; }
  Toe minimax(int x, int y);

 private:
  Toe player1 = Tic, player2 = Tac;
  Mode mode;
  int score1 = 0, score2 = 0;
  bool player = 0;
  Status status = NOTHING;
  Field* field;
  // std::mt19937 gen;
};

#endif  // MODEL_H
