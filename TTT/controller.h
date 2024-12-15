#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"

class controller {
 public:
  controller(model* m) : m_(m) {}
  Toe** getCells() { return m_->getArray(); }

  Toe press(float x, float y) { return m_->setT(x / 200, y / 200); }
  void clear() { m_->clear(); }
  bool checkFull() { return m_->checkFull(); }
  Toe computerMove() { return m_->computerMove(); }

 private:
  model* m_;
};

#endif  // CONTROLLER_H
