#ifndef MODEL_H
#define MODEL_H

#include <qdebug.h>

#include <QString>
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
  void print() {
    char c1, c2, c3;
    for (int i = 0; i < 3; ++i) {
      c1 = ts[i][0] == Tic ? 'O' : ts[i][0] == Tac ? 'X' : '.';
      c2 = ts[i][1] == Tic ? 'O' : ts[i][1] == Tac ? 'X' : '.';
      c3 = ts[i][2] == Tic ? 'O' : ts[i][2] == Tac ? 'X' : '.';

      qDebug() << QString("%1 %2 %3").arg(c1).arg(c2).arg(c3);
    }
    qDebug() << '\n';
  }

 private:
  Toe** ts = nullptr;
};

class model {
 public:
  model(Mode m) : mode(m), field(new Field) {}
  Field getField() { return *field; }
  void setT(int x, int y);
  Toe winnerCheck(Field& f);
  void clear();
  bool checkFull(Field& f);
  void computerMove();
  void doMove(int x, int y);
  bool isValid(int x, int y);
  Status getStatus() { return status; }
  void update();
  int getScore1() { return score1; }
  int getScore2() { return score2; }
  Toe minimax(int x, int y);
  int AI(int x, int y, Field field, Toe toe);

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
