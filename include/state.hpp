#pragma once
#include <iostream>

class Grid;
class State {
 public:
  virtual int vecinos(const Grid&, int i, int j) = 0;
  virtual char getState() const =0;
  virtual State* nextState()=0;

};
