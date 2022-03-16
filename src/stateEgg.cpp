#include "../include/stateEgg.hpp"
char StateEgg::getState() const
{
  return 'e';
}
int StateEgg::vecinos(const Grid &board, int i, int j)
{
    std::cout << "entra en egg";

  int counter = 0;
  int huevo = 0;
  vecinaLarva_ = 0;
  vecinaHuevo_ = 0;
  // bucle para mirar todas las posiciones de las vecinas
  for (int k = i - 1; k <= i + 1; k++)
  {
    for (int l = j - 1; l <= l + 1; l++)
    {
      // evitamos contar la posicion en la que estamos
      if (k != i || l != j)
        // comprobamos si es adulta
        if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'l')
          counter++;
        else if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'e')
        {
          huevo++;
        }
    }
  }
  vecinaHuevo_ = huevo;
  vecinaLarva_ = counter;

  return 1;
}
State *StateEgg::nextState()
{
  if (vecinaHuevo_ < vecinaLarva_)
  {
    StateMuerta *ptr2 = new StateMuerta;
    return ptr2;
  }
  else
  {
    StateAdult *ptr2 = new StateAdult;
    return ptr2;
  }
}
