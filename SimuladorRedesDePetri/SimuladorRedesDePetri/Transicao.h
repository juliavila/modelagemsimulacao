#pragma once
#include "Arco.h"
#include "Lugar.h"
#include <vector>

class Transicao
{
private:
	vector<Arco> arcosOrigem;
	vector<Lugar> lugaresOrigem;

	vector<Arco> arcosDestino;
	vector<Lugar> lugaresDestino;

	bool habilitado;


	void tentarHabilitar();

public:
	Transicao();
	~Transicao();

	vector<Arco> getArcosOrigem();
	void setArcoOrigem(Arco);
	vector<Lugar> getLugaresOrigem();
	void setLugarOrigem(Lugar);
	vector<Arco> getArcosDestino();
	void setArcoDestino(Arco);
	vector<Lugar> getLugaresDestino();
	void setLugarDestino(Lugar);

	void executar();
};

