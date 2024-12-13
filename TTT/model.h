#ifndef MODEL_H
#define MODEL_H

#include <QMatrix3x3>
#include <array>
#include <iostream>

typedef enum { No, Tic, Tac } Toe;

class model {
 public:
  model() {
    ts = new Toe*[3];

    for (int i = 0; i < 3; ++i) {
      ts[i] = new Toe[3];
    }

    // std::pair p = std::make_pair(0, No);
    // for (int i = 0; i < 3; ++i) {
    //   for (int j = 0; j < 3; ++j) {
    //     ts[i][j] = p;
    //   }
    // }
  }
  Toe** getArray() { return ts; }
  Toe setT(int x, int y);
  Toe winnerCheck();
  void clear();

 private:
  Toe** ts = {};
  Toe cur = Tac;
};

#endif  // MODEL_H
