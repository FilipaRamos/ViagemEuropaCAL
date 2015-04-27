
#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include "Files.h"
#include "Cidade.h"
#include "Graph.h"
#include "Viagem.h"
#include "Path.h"
#include "ShowGraph/DisplayGraph.h"
#include "Knapsackproblem.h"

using namespace std;

int main(){

	int tempo_total;
	int option;
	string nome;
	DisplayGraph gd;

	cout << "Qual o ficheiro a ler ?" << endl;
	cin >> nome;
	cout << "Ficheiro " << nome  << " a ser aberto....... " << endl;
	cout << ".......................................... " << endl;

	File file (nome);
	tempo_total = file.readFile();
	if(tempo_total == -1)
		return 0;

	Path p;
	p.createGraph(file);

	vector<Cidade> cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);

	cout << " Opções: " << endl;
	cout << " 1. Visualizar grafo inicial" << endl;
	cout << " 2. Calcular as cidades a visitar" << endl;
	cout << " 3. Calcular o tempo que demoraria a visitar todas as cidades" << endl;

	cin >> option;
	switch(option){
	case 1:
		gd.Display(p.getGraph());
		cin.get();
		Sleep(100000000);
		break;
	case 2:
		while (!FWShortestPath(p, cidadesAusar, tempo_total)) {
			tempo_total--;
			cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);
		}
		DisplayGraphFW(p, cidadesAusar);
		break;
	case 3:
		p.CalculaCaminho();
		break;
	default:
		break;
	}

	return 0;
}

