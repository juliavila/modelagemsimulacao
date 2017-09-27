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

list<arco*>* Lugar::getArcos()
{
	return &arcos;
}

void Lugar::setMarca(int m)
{
	marcas = m;
}

void Lugar::setArcos(list<arco*> a)
{
	arcos = a;
}

void Lugar::addMarcas(int m)
{
	marcas += m;
}

void Lugar::addArco(arco *a)
{
	arcos.push_back(a);
}

void Lugar::removeMarcas(int m)
{
	marcas -= m;
}

//void Lugar::removeArco(arco a)
//{
//	arcos.remove(arcos[ap]);
//}