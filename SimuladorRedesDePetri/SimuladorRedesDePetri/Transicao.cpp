#include "Transicao.h"



Transicao::Transicao()
{
	this->habilitado = false;
}

Transicao::~Transicao()
{
}

vector<Arco*> Transicao::getArcosOrigem()
{
	return this->arcosOrigem;
}

void Transicao::setArcoOrigem(Arco* arco)
{
	this->arcosOrigem.push_back(arco);
}

vector<Lugar*> Transicao::getLugaresOrigem()
{
	return this->lugaresOrigem;
}

void Transicao::setLugarOrigem(Lugar *lugar)
{
	this->lugaresOrigem.push_back(lugar);
}

vector<Arco*> Transicao::getArcosDestino()
{
	return this->arcosDestino;
}

void Transicao::setArcoDestino(Arco *arco)
{
	this->arcosDestino.push_back(arco);
}

vector<Lugar*> Transicao::getLugaresDestino()
{
	return this->lugaresDestino;
}

void Transicao::setLugarDestino(Lugar *lugar)
{
	this->lugaresDestino.push_back(lugar);
}

void Transicao::executar()
{
	if (this->habilitado)
	{
		//consome marcas
		for (int i = 0; i < this->arcosOrigem.size(); i++)
		{
			this->lugaresOrigem[i]->removeMarcas(this->arcosOrigem[i]->getPeso());
		}

		//gera marcas
		for (int i = 0; i < this->arcosDestino.size(); i++)
		{
			this->lugaresDestino[i]->addMarcas(this->arcosDestino[i]->getPeso());
		}

		this->habilitado = false;
	}

	tentarHabilitar();	
}

void Transicao::tentarHabilitar()
{
	// verifica se todos os lugares de origem tem marcas >= peso de cada arco
	bool habilitar = true;
	for (int i = 0; i < this->arcosOrigem.size(); i++)
	{
		if (this->arcosOrigem[i]->getPeso() > this->lugaresOrigem[i]->getMarcas())
		{
			habilitar = false;
			break;
		}
	}

	if (habilitar)
		this->habilitado = true;
}

bool Transicao::getHabilitado()
{
	return habilitado;
}