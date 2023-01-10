#pragma once
#include "Carta.h"

class Seleccionado
{
private:
	int valor;
	int index;

public:
	Seleccionado(int valor, int index);

	int getIndex();

	int getValor();
};

