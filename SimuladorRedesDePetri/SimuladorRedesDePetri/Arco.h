#pragma once

class Arco
{
private:
	bool tipoOrigem; //lugar(0) ou transição(1)
	int origem;
	int destino;
	int peso;
public:
	Arco();
	~Arco();

	bool getTipoOrigem();
	void setTipoOrigem(bool tipoOrigem);
	int getOrigem();
	void setOrigem(int origem);
	int getDestino();
	void setDestino(int destino);
	int getPeso();
	void setPeso(int peso);
};
