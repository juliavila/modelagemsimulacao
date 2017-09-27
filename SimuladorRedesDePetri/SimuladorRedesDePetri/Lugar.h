#pragma once
#include <list>
using namespace std;

class Lugar
{
private:
	int marcas;
public:
	Lugar();
	~Lugar();

	int getMarcas();

	void setMarca(int);

	void addMarcas(int);
	void removeMarcas(int);
};
