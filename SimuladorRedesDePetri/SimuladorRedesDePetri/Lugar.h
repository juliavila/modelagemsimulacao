#pragma once
#include <list>
using namespace std;

class arco;

class Lugar
{
private:
	int marcas;
	list<arco*> arcos;
public:
	Lugar();
	~Lugar();

	int getMarcas();
	list<arco*>* getArcos();

	void setMarca(int);
	void setArcos(list<arco*>);

	void addMarcas(int);
	void addArco(arco*);
	void removeMarcas(int);
	/*void removeArco(int);*/
};
