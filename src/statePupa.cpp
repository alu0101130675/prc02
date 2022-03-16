#include "../include/statePupa.hpp"
char StatePupa::getState() const
{
  return 'p';
}
int StatePupa::vecinos(const Grid &board, int i, int j)
{
    std::cout << "entra en pupa";

  num_adulta = 0;
  num_huevo = 0;
  num_larva = 0;
  num_muertas = 0;
  num_pupas = 0;
  int contadorAdulta = 0;
  int contadorhuevo = 0;
  int contadorLarva = 0;
  int contadorMuertas = 0;
  int contadorPupas = 0;
  // bucle para mirar todas las posiciones de las vecinas
  for (int k = i - 1; k <= i + 1; k++)
  {
    for (int l = j - 1; l <= l + 1; l++)
    {
      // evitamos contar la posicion en la que estamos
      if (k != i || l != j)
        // comprobamos si es adulta
        if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'a')
          contadorAdulta++;
        else if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'e')
          contadorhuevo++;
        else if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'l')
          contadorLarva++;
        else if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == 'p')
          contadorPupas++;
        else if (board.get_Malla()[i * board.get_Columnas() + j]->getState() == ' ')
          contadorMuertas++;
    }
    num_adulta = contadorAdulta;
    num_huevo = contadorhuevo;
    num_larva = contadorLarva;
    num_muertas = contadorMuertas;
    num_pupas = contadorPupas;
  }
  return 1;
}
State *StatePupa::nextState()
{
  if (num_larva < num_huevo || num_larva < num_muertas || num_larva < num_pupas || num_larva < num_adulta)
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