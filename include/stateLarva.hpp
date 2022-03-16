#pragma once
#include "state.hpp"
#include "grid.hpp"
class StateLarva : public State
{
private:
   int vecinaLarva_;
   int resto_;

public:
   char getState() const;
   int vecinos(const Grid &, int i, int j);
   State *nextState();
};
