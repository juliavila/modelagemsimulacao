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

void init(vector<Transicao> *transicoes, vector<Lugar> *lugares, vector<Arco> *arcos)
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
		lugares->push_back(*lugar);


		cout << endl << "Lugar " << i << ": ";
		cin >> nroMarcas;

		(*lugares)[i].setMarca(nroMarcas);
	}

	cout << endl << "Informe o numero de Transicoes: ";
	cin >> nroTransicoes;

	for (int i = 0; i < nroTransicoes; i++)
	{
		Transicao *transicao = new Transicao();

		//---------------------------------------------- LUGARES DE ORIGEM --------------------------------------------

		string lugaresOrigem;
		cout << "\n Para a transicao " << i << " informe:\n\t os lugares de origem(separados por ',' se houver mais de um): ";
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
			lugaresOrigem.replace(0, virgulaPos + 1, ""); // apaga o que foi copiado

			int posLugar = stringToInt(aux); // converte string para int

			transicao->setLugarOrigem(&(*lugares)[posLugar]); // finalmente seta um lugar de origem
		}

		//---------------------------------------------- ARCOS DE ORIGEM --------------------------------------------

		for (int x = 0; x < transicao->getLugaresOrigem().size(); x++) // pede o peso do arco para cada lugar de origem para cada lugar de origem
		{
			Arco *arco = new Arco();
			int pesoArco = 1;

			cout << "\t qual o peso do arco que vem do " << x + 1 << " lugar de origem?";
			cin >> pesoArco;
			if (pesoArco < 1)
			{
				pesoArco = 1;
			}

			arco->setPeso(pesoArco);

			arcos->push_back(*arco); // adiciona o arco no vector de arcos

			transicao->setArcoOrigem(&arcos->back()); // adiciona o ultimo arco (que vai ser o mais novo) como arco de origem
		}

		//---------------------------------------------- LUGARES DE DESTINO --------------------------------------------

		string lugaresDestino;
		cout << "\t os lugares de destino(separados por ',' se houver mais de um): ";
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

			transicao->setLugarDestino(&(*lugares)[posLugar]); // finalmente seta um lugar de origem
		}

		//---------------------------------------------- ARCOS DE DESTINO --------------------------------------------

		for (int x = 0; x < transicao->getLugaresOrigem().size(); x++) // pede o peso do arco para cada lugar de origem para cada lugar de origem
		{
			Arco *arco = new Arco();
			int pesoArco = 1;

			cout << "\t qual o peso do arco que vem do " << x + 1 << "° lugar de destino?";
			cin >> pesoArco;
			if (pesoArco < 1)
			{
				pesoArco = 1;
			}

			arco->setPeso(pesoArco);

			arcos->push_back(*arco); // adiciona o arco no vector de arcos

			transicao->setArcoOrigem(&arcos->back()); // adiciona o ultimo arco (que vai ser o mais novo) como arco de origem
		}

		transicoes->push_back(*transicao);
	}
}

void imprime(vector<Transicao> *transicoes, vector<Lugar> *lugares, vector<Arco> *arcos)
{
	cout << endl << "LUGARES:" << endl;
	cout << "total: " << lugares->size() << endl;
	for (int i = 0; i < lugares->size(); i++)
	{
		cout << i << " - marcas: " << (*lugares)[i].getMarcas() << endl;
	}
	/************************************/
	cout << endl << "TRANSICOES:" << endl;
	cout << "total: " << transicoes->size() << endl;
	for (int x = 0; x < transicoes->size(); x++)
	{
		cout << x << " - habilitada: " << (*transicoes)[x].getHabilitado() << endl;
	}
	/************************************/
	cout << endl << "ARCOS:" << endl;
	cout << "total; " << arcos->size() << endl;
	for (int i = 0; i < arcos->size(); i++)
	{
		cout << i << " - peso: " << (*arcos)[i].getPeso() << endl;
	}

	system("pause");
}

int main()
{
	vector<Transicao> transicoes;
	vector<Lugar> lugares;
	vector<Arco> arcos;

	//init(&transicoes, &lugares, &arcos);

	Lugar *lugar = new Lugar();
	lugares.push_back(*lugar);
	lugares[0].setMarca(1);

	lugar = new Lugar();
	lugares.push_back(*lugar);
	lugares[1].setMarca(2);

	lugar = new Lugar();
	lugares.push_back(*lugar);
	lugares[2].setMarca(0);

	lugar = new Lugar();
	lugares.push_back(*lugar);
	lugares[3].setMarca(1);

	lugar = new Lugar();
	lugares.push_back(*lugar);
	lugares[4].setMarca(0);

	Transicao *transicao = new Transicao();
	transicoes.push_back(*transicao);
	transicoes[0].setLugarOrigem(&lugares[0]);
	transicoes[0].setLugarOrigem(&lugares[1]);
	transicoes[0].setLugarDestino(&lugares[1]);
	transicoes[0].setLugarDestino(&lugares[2]);

	transicao = new Transicao();
	transicoes.push_back(*transicao);
	transicoes[1].setLugarOrigem(&lugares[2]);
	transicoes[1].setLugarOrigem(&lugares[3]);
	transicoes[1].setLugarDestino(&lugares[4]);
	
	Arco *arco = new Arco();
	arcos.push_back(*arco);
	arcos[0].setPeso(1);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[1].setPeso(2);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[2].setPeso(2);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[3].setPeso(1);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[4].setPeso(1);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[5].setPeso(1);

	arco = new Arco();
	arcos.push_back(*arco);
	arcos[6].setPeso(1);

	transicoes[0].setArcoOrigem(&arcos[0]);
	transicoes[0].setArcoOrigem(&arcos[1]);
	transicoes[0].setArcoDestino(&arcos[2]);
	transicoes[0].setArcoDestino(&arcos[3]);

	transicoes[1].setArcoOrigem(&arcos[4]);
	transicoes[1].setArcoOrigem(&arcos[5]);
	transicoes[1].setArcoDestino(&arcos[6]);

	imprime(&transicoes, &lugares, &arcos);

	//------------------------------------------------------ MAIN LOOP ----------------------------------------------

	while (true)
	{
		bool interrompe = true; // variavel para saber se nao existem mais transicoes habilitadas, se existir, sera false
		for (int x = 0; x < transicoes.size(); x++) // primeiro for checa e habilita transicoes
		{
			transicoes[x].executar();

			if (transicoes[x].getHabilitado())
			{
				interrompe = false;
			}
		}

		imprime(&transicoes, &lugares, &arcos);

		if (interrompe)
		{
			break;
		}
	}
	return 0;
}

//void main()
//{
//	int i = 0;
//	while (true)
//	{
//		cin >> i;
//		if (i == 200)
//		{
//			break;
//		}
//	}
//}