#include "../include/celula.hpp"
#include "../include/grid.hpp"
#include "../include/muerta.hpp"

Celula::Celula(int i, int j)
{
	set_Posicion(i, j);
	StateMuerta *ptr2 = new StateMuerta;
	setState(ptr2);
}

char Celula::getState(void) const
{
	// modificado el get estado
	return estado_->getState();
}
State *Celula::get_Estado() const
{
	// modificado el get estado
	return estado_;
}

std::pair<int, int> Celula::get_Posicion(void)
{
	return posicion_;
}

/*int Celula::get_VecinasVivas(void)
{
	return num_vecinas_vivas_;
}*/

void Celula::setState(State *estado)
{
	estado_ = estado;
}

void Celula::set_Posicion(std::pair<int, int> pos)
{
	posicion_ = pos;
}

void Celula::set_Posicion(int i, int j)
{
	posicion_ = std::make_pair(i, j);
}

/*void Celula::set_VecinasVivas(int num)
{
	num_vecinas_vivas_ = num;
}
*/
int Celula::actualizarEstado(void)  {
	setState(estado_->nextState());
return 1;
}

std::ostream &operator<<(std::ostream &cout, const Celula cel)
{
	cout << cel.getState();
	return cout;
}