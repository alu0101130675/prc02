#include <iostream>
#pragma once
#include "state.hpp"

class Grid;
class Celula 
{
	
	private:
		State* estado_;
		std::pair<int, int> posicion_; 
		State* nextState;


	public:
		Celula(){};
		Celula(int i, int j);
		~Celula(){};

		State* get_Estado() const;
		std::pair<int, int> get_Posicion(void);
		int get_VecinasVivas(void);
		char getState() const;
    void setState(State*);
		void set_Posicion(std::pair<int, int> pos);
		void set_Posicion(int i, int j);
		void set_VecinasVivas(int num);
		int actualizarEstado(void);
		int contarVecinas(const Grid& board);
		friend std::ostream& operator<<(std::ostream& cout, const Celula celuu);
};