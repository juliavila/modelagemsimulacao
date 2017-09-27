#include "Arco.h"


Arco::Arco()
{
	this->peso = 1;
}


Arco::~Arco()
{
}

bool Arco::getTipoOrigem()
{
	return this->tipoOrigem;
}
void Arco::setTipoOrigem(bool tipoOrigem)
{
	this->tipoOrigem = tipoOrigem;
}
int Arco::getOrigem()
{
	return this->origem;
}
void Arco::setOrigem(int origem)
{
	this->origem = origem;
}
int Arco::getDestino()
{
	return this->destino;
}
void Arco::setDestino(int destino)
{
	this->destino = destino;
}
int Arco::getPeso()
{
	return this->peso;
}
void Arco::setPeso(int peso)
{
	this->peso = peso;
}