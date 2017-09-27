#include "Arco.h"

Arco::Arco()
{
	this->peso = 1;
}

Arco::~Arco()
{
}

int Arco::getPeso()
{
	return this->peso;
}
void Arco::setPeso(int peso)
{
	this->peso = peso;
}