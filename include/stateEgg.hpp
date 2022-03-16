#pragma once
#include "state.hpp"
#include "grid.hpp"
class StateEgg : public State {
   private:
   int vecinaLarva_;
   int vecinaHuevo_;
 public:
  char getState() const;
   int vecinos(const Grid&, int i, int j);
   State* nextState();

};
