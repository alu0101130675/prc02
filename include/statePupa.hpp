#pragma once
#include "state.hpp"
#include "grid.hpp"

class StatePupa : public State {
  private:
  int num_pupas;
  int num_muertas;
  int num_larva;
  int num_adulta;
  int num_huevo;
 public:
  char getState() const;
  int vecinos(const Grid &board, int i, int j);
  State* nextState();

};
