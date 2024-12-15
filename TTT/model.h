#ifndef MODEL_H
#define MODEL_H

#include <array>
#include <iostream>

typedef enum { No, Tic, Tac, Bad } Toe;

class model {
 public:
  model() {
    ts = new Toe*[3];
    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }
  }
  Toe** getArray() { return ts; }
  Toe setT(int x, int y);
  Toe winnerCheck();
  void clear();
  bool checkFull();
  Toe computerMove();

 private:
  Toe** ts = {};
  Toe cur;
};

#endif  // MODEL_H
