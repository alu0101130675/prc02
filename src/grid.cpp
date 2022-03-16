#include "../include/grid.hpp"
Grid::Grid(int N, int M, int turnos)
{
	assert(N > 2 && M > 2);
	assert(turnos >= 1);
	inicializar(N, M, turnos);
	crearCelulasInicio();
	juegoDeLaVida();
	cambianEstado = 0;
}

Celula **Grid::get_Malla(void) const
{
	return malla_;
}

unsigned Grid::get_TurnosTotal(void)
{
	return turnos_total_;
}

unsigned Grid::get_TurnoActual(void)
{
	return turno_actual_;
}

unsigned Grid::get_Columnas(void) const
{
	return columnas_;
}

unsigned Grid::get_Filas(void)
{
	return filas_;
}

void Grid::set_Malla(Celula **malla)
{
	malla_ = malla;
}

void Grid::set_TurnosTotal(int turno)
{
	turnos_total_ = turno;
}

void Grid::set_TurnoActual(int turno)
{
	turno_actual_ = turno;
}

void Grid::set_Columnas(int columna)
{
	columnas_ = columna;
}

void Grid::set_Filas(int filas)
{
	filas_ = filas;
}

void Grid::crearCelulasInicio(void)
{
	int counter = 0;
	std::cout << "¿Numero de celulas vivas?";
	std::cin >> counter;
	std::cout << "Indique las posiciones (i , j) de la célula: " << std::endl;
	while (counter > 0)
	{
		int pos_i = 0, pos_j = 0;
		std::cout << "[" << counter << "]: ";
		std::cin >> pos_i >> pos_j;
		std::cout << "Indique el tipo de celula: p=Pupa, l =larva, e=egg a= adult" << std::endl;
		char tipo;
		std::cin >> tipo;
		if (tipo == 'p')
		{
			StatePupa *Celula = new StatePupa;
			malla_[pos_i * get_Columnas() + pos_j]->setState(Celula);
		}
		else if (tipo == 'l')
		{
			StateLarva *Celula = new StateLarva;
			malla_[pos_i * get_Columnas() + pos_j]->setState(Celula);
		}
		else if (tipo == 'e')
		{
			StateEgg *Celula = new StateEgg;
			malla_[pos_i * get_Columnas() + pos_j]->setState(Celula);
		}
		else if (tipo == 'a')
		{
			StateAdult *Celula = new StateAdult;
			malla_[pos_i * get_Columnas() + pos_j]->setState(Celula);
		}
		else
		{
			StateMuerta *Celula = new StateMuerta;
			malla_[pos_i * get_Columnas() + pos_j]->setState(Celula);
		}
		counter--;
	}
}

void Grid::inicializar(int N, int M, int turnos)
{
	set_Columnas(M + 2);
	set_Filas(N + 2);
	malla_ = new Celula *[(N + 2) * (M + 2)];
	for (int i = 0; i < N + 2; i++)
		for (int j = 0; j < M + 2; j++)
			malla_[i * (M + 2) + j] = new Celula(i, j);

	set_TurnoActual(0);
	set_TurnosTotal(turnos);
}

void Grid::juegoDeLaVida(void)
{
	set_TurnoActual(0);
	for (int i = 0; i < get_TurnosTotal(); i++)
	{
		std::cout << std::endl
							<< "Turno: " << get_TurnoActual() + 1 << std::endl;
		if (i > 0)
			std::cout << "Cambian " << cambianEstado << " celulas." << std::endl;

		write();
									std::cout << "despues de imprimri";
		siguienteTurno();
		turno_actual_++;
	}
}

void Grid::siguienteTurno(void)
{
								std::cout << "contanod vecinas";

	int counter = 0;
	for (int i = 1; i < get_Filas() - 1; i++)
		for (int j = 1; j < get_Columnas() - 1; j++){
							std::cout << "contanod vecinas";

			malla_[i * get_Columnas() + j]->get_Estado()->vecinos(*this,i,j);
			}
/*
	for (int i = 1; i < get_Filas() - 1; i++)
		for (int j = 1; j < get_Columnas() - 1; j++){
					std::cout << "actualizando";

						malla_[i * get_Columnas() + j] -> actualizarEstado();

		}

	cambianEstado = counter;*/
}

void Grid::write(void)
{
	for (int i = 1; i < get_Filas() - 1; i++)
	{
		for (int j = 1; j < get_Columnas() - 1; j++)
			std::cout << *malla_[i * get_Columnas() + j] << " ";

		std::cout << std::endl;
	}
}