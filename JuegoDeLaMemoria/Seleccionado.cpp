#include "Seleccionado.h"

Seleccionado::Seleccionado(int valor, int index)
{
	this->valor = valor;
	this->index = index;
}

int Seleccionado::getIndex()
{
	return this->index;
}

int Seleccionado::getValor()
{
	return this->valor;
}
