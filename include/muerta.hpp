#pragma once
#include "state.hpp"
#include "grid.hpp"

class StateMuerta : public State {
  private: 
   int vecinas_;
 public:
 int vecinos(const Grid&, int i, int j);
  char getState() const;
  State* nextState();

};
