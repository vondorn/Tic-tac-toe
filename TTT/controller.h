#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"

class controller {
 public:
  controller(model* m) : m_(m) {}
  Field getCells() { return m_->getField(); }

  void press(float x, float y) { m_->doMove(x / 200, y / 200); }
  void clear() { m_->clear(); }
  bool checkFull() { return m_->checkFull(); }
  Status getStatus() { return m_->getStatus(); }
  // void computerMove() { m_->computerMove(); }
  int getScore1() { return m_->getScore1(); }
  int getScore2() { return m_->getScore2(); }

 private:
  model* m_;
};

#endif  // CONTROLLER_H
