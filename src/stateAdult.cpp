#include "../include/stateAdult.hpp"
char StateAdult::getState() const {
  return 'a';
}
int StateAdult::vecinos(const Grid &board, int i, int j)
{
  std::cout << "entra en adulto";
  int counter = 0;
  vecinas_=0;
  // bucle para mirar todas las posiciones de las vecinas
  for (int k = i - 1; k <= i + 1; k++)
  {
    for (int l = j - 1; l <= l + 1; l++)
    {
      // evitamos contar la posicion en la que estamos
      if (k != i || l != j)
        // comprobamos si es adulta
        if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'a')
          counter++;
    }
  }
  vecinas_=counter;
  return 1;
}
State* StateAdult::nextState() {
  if (vecinas_>0)
  {
    StateEgg *ptr2 = new StateEgg;
    return 	ptr2;
  }  
  else {
        StateMuerta *ptr2 = new StateMuerta;
    return 	ptr2;
  }
}