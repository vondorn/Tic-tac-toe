#ifndef MODEL_H
#define MODEL_H

#include <array>
#include <iostream>

typedef enum { No, Tic, Tac, Bad } Toe;
typedef enum { ONE, TWO } Mode;
typedef enum { NOTHING, DRAW, WIN_FIRST, WIN_SECOND } Status;

class model {
 public:
  model(Mode m) : mode(m) {
    ts = new Toe*[3];
    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }
  }
  Toe** getArray() { return ts; }
  void setT(int x, int y);
  void winnerCheck();
  void clear();
  bool checkFull();
  void computerMove();
  void doMove(int x, int y);
  bool isValid(int x, int y);

 private:
  Toe** ts = {};
  Toe player1 = Tic, player2 = Tac;
  Mode mode;
  int score1 = 0, score2 = 0;
  bool player = 0;
  Status status = NOTHING;
};

#endif  // MODEL_H
