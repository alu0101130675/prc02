#pragma once
#include "state.hpp"
#include "grid.hpp"

class StateAdult : public State {
   private:
   int vecinas_;
 public:
  char getState() const;
   int vecinos(const Grid&, int i, int j);
   State* nextState();

};
