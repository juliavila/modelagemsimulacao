#include "Lugar.h"

#include "Lugar.h"

Lugar::Lugar()
{
	marcas = 0;
}

Lugar::~Lugar()
{

}

int Lugar::getMarcas()
{
	return marcas;
}

void Lugar::setMarca(int m)
{
	marcas = m;
}

void Lugar::addMarcas(int m)
{
	marcas += m;
}

void Lugar::removeMarcas(int m)
{
	marcas -= m;
}