#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"

class controller {
 public:
  controller(model* m) : m_(m) {}
  Toe** getCells() { return m_->getArray(); }

  void press(float x, float y) { m_->doMove(x / 200, y / 200); }
  void clear() { m_->clear(); }
  bool checkFull() { return m_->checkFull(); }
  // void computerMove() { m_->computerMove(); }

 private:
  model* m_;
};

#endif  // CONTROLLER_H
