#pragma once
#include <vector>
#include <cassert>
#include "celula.hpp"
#include "../include/stateEgg.hpp"
#include "../include/stateLarva.hpp"
#include "../include/statePupa.hpp"
#include "../include/stateAdult.hpp"
#include "../include/muerta.hpp"

class Grid
{
	private:
		// Attribs
		Celula** malla_;
		unsigned turnos_total_;
		unsigned turno_actual_;
		unsigned columnas_;
		unsigned filas_;
		int cambianEstado;

	public:
		// Builders & Destroyer
		Grid(){};
		Grid(int N, int M, int turnos);
		~Grid(){};

		// Getters & Setters
		Celula** get_Malla(void) const;
		unsigned get_TurnosTotal(void);
		unsigned get_TurnoActual(void);
		unsigned get_Columnas(void) const;
		unsigned get_Filas(void);

		void set_Malla(Celula** malla);
		void set_TurnosTotal(int turno);
		void set_TurnoActual(int turno);
		void set_Columnas(int columna);
		void set_Filas(int filas);		

		// Functions
		void crearCelulasInicio(void);
		void inicializar(int N, int M, int turnos);

		void juegoDeLaVida(void);
		void siguienteTurno(void);

		// Write
		void write(void);
};