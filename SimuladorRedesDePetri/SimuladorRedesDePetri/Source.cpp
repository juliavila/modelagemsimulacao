// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <iostream>
#include <string>
#include "Lugar.h"
#include "Arco.h"
#include "Transicao.h"


using namespace std;

int stringToInt(string s)
{
	int ret = 0; // variavel quye vai ser retornada

	int size = s.size();

	for (int x = 0; x < size; x++)
	{
		int n = ((int)s.back() - 48)*pow(10, x);
		ret += n;
		s.pop_back();
	}

	return ret;
}

void init(vector<Transicao> t, vector<Lugar> l, vector<Arco> a)
{
	int nroLugares;
	int nroTransicoes;
	//int nroArcos;

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
		l.push_back(*lugar);


		cout << endl << "Lugar " << i << ": ";
		cin >> nroMarcas;

		l[i].setMarca(nroMarcas);
	}

	cout << endl << "Informe o numero de Transicoes: ";
	cin >> nroTransicoes;

	for (int i = 0; i < nroTransicoes; i++)
	{
		Transicao *transicao = new Transicao();

		//---------------------------------------------- LUGARES DE ORIGEM --------------------------------------------

		string lugaresOrigem;
		cout << "Para a transicao " << i << " informe:\n\t os lugares de origem(separados por , se houver mais de um): ";
		cin >> lugaresOrigem;
		string aux; // string usada para quebrar os lugares

		while (lugaresOrigem.size() > 0)
		{
			int virgulaPos = lugaresOrigem.find(","); // acha a posicao de uma vergula se houver, se nao houver virgula, o valor retornado sera igual a string::npos

			if (virgulaPos == string::npos) // nao ha virgula
			{
				virgulaPos = lugaresOrigem.size(); // se nao houver virgula, faz o seguinte em a string inteira
			}

			aux = lugaresOrigem.substr(0, virgulaPos); // copia o que vem antes da virgula em uma string diferente
			lugaresOrigem.replace(0, virgulaPos+1, ""); // apaga o que foi copiado

			int posLugar = stringToInt(aux); // converte string para int

			transicao->setLugarOrigem(&l[posLugar]); // finalmente seta um lugar de origem
		}

		//---------------------------------------------- ARCOS DE ORIGEM --------------------------------------------

		//---------------------------------------------- LUGARES DE DESTINO --------------------------------------------

		string lugaresDestino;
		cout << "\t os lugares de destino(separados por , se houver mais de um): ";
		cin >> lugaresDestino;

		while (lugaresDestino.size() > 0)
		{
			int virgulaPos = lugaresDestino.find(","); // acha a posicao de uma vergula se houver, se nao houver virgula, o valor retornado sera igual a string::npos

			if (virgulaPos == string::npos) // nao ha virgula
			{
				virgulaPos = lugaresDestino.size(); // se nao houver virgula, faz o seguinte em a string inteira
			}

			aux = lugaresDestino.substr(0, virgulaPos); // copia o que vem antes da virgula em uma string diferente
			lugaresDestino.replace(0, virgulaPos + 1, ""); // apaga o que foi copiado

			int posLugar = stringToInt(aux); // converte string para int

			transicao->setLugarDestino(&l[posLugar]); // finalmente seta um lugar de origem
		}

		//---------------------------------------------- ARCOS DE DESTINO --------------------------------------------

		//alimentar as transicoes aqui
	}
}

int main()
{
	vector<Transicao> transicoes;
	vector<Lugar> lugares;
	vector<Arco> arcos;

	int nroLugares;
	int nroTransicoes;
	//int nroArcos;

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

	for (int i = 0; i < nroTransicoes; i++)
	{
		//alimentar as transicoes aqui
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
	//complementar teste de transicoes
	/************************************/
	cout << endl << "ARCOS:" << endl;
	cout << "total; " << arcos.size();
	for (int i = 0; i < arcos.size(); i++)
	{
		cout << i << " - peso: " << arcos[i].getPeso() << endl;
	}
	/************************************/
	//system("pause");
	return 0;
}

//int main()
//{
//	string str = "ola, meu nome eh julia";
//	string str2;
//	int i = str.find(",");
//
//	str2 = str.substr(0, i);
//
//	str.replace(0, str.size(), "");
//
//	cout << str.size() << endl << str2 << endl;
//
//	system("pause");
//
//	return 0;
//}