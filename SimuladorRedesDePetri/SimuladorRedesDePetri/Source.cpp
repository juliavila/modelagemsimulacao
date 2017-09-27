// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <iostream>
#include <string>
#include "Lugar.h"
#include "Arco.h"


using namespace std;

int main()
{
	vector<int> testInt;
	vector<Lugar> lugares;
	vector<Arco> arcos;

	int nroLugares;
	int nroTransicoes;
	int nroArcos;

	string strLugar = "o Lugar";
	string strTran = "a Transicao";

	cout << "Informe o numero de Lugares:";
	cin >> nroLugares;

	//lugares = vector<Lugar>(nroLugares);

	cout << endl << "Informe o numero inicial de marcacoes em cada Lugar:" << endl;
	for (int i = 0; i < nroLugares; i++)
	{
		int nroMarcas = 0;

		Lugar *lugar = new Lugar();
		lugares.push_back(*lugar);


		cout << endl << "Lugar " << i << ": ";
		cin >> nroMarcas;

		lugares[i].setMarca(nroMarcas);
	}

	cout << endl << "Informe o numero de Transicoes: ";
	cin >> nroTransicoes;

	cout << endl << "Informe o numero de Arcos: ";
	cin >> nroArcos;

	//arcos = vector<Arco>(nroArcos);

	for (int i = 0; i < nroArcos; i++)
	{
		int tipoOrigemArco = 0;
		int pesoArco = 0;
		int lugarOrigem;
		int lugarDestino;

		Arco *arco = new Arco();
		arcos.push_back(*arco);

		cout << endl << "A origem deste arco eh um Lugar (digite 0) ou uma Transicao (digite 1)?";
		cin >> tipoOrigemArco;

		cout << endl << "Informe " << (!tipoOrigemArco ? strLugar : strTran) << " de Origem:";
		cin >> lugarOrigem;
		cout << endl << "Informe " << (tipoOrigemArco ? strLugar : strTran) << " de Destino:";
		cin >> lugarDestino;

		cout << endl << "Informe o peso do Arco: ";
		cin >> pesoArco;

		arcos[i].setTipoOrigem(tipoOrigemArco);
		arcos[i].setOrigem(lugarOrigem);
		arcos[i].setDestino(lugarDestino);
		arcos[i].setPeso(pesoArco);

	}

	/**
	* TESTES
	**/
	/************************************/
	cout << endl << "LUGARES:" << endl;
	cout << "total: " << lugares.size() << endl;
	for (int i = 0; i < lugares.size(); i++)
	{
		cout << i << " - marcas: " << lugares[i].getMarcas() << endl;
	}
	/************************************/
	cout << endl << "TRANSICOES:" << endl;
	cout << "total: " << nroTransicoes << endl;
	/************************************/
	cout << endl << "ARCOS:" << endl;
	cout << "total; " << arcos.size();
	for (int i = 0; i < arcos.size(); i++)
	{
		cout << i << " - tipo origem: " << arcos[i].getOrigem() << "; origem: " << arcos[i].getOrigem() << "; destino: " << arcos[i].getDestino() << "; peso: " << arcos[i].getPeso() << endl;
	}
	/************************************/
	system("pause");
	return 0;
}
