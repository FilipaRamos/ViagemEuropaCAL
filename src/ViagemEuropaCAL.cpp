
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

	vector<Cidade> cidadesAusar = file.viagem.getCidades();

	cout << " Opções: " << endl;
	cout << " 1. Visualizar grafo inicial" << endl;
	cout << " 2. Calcular as cidades a visitar" << endl;
	cout << " 3. Calcular o tempo que demoraria a visitar todas as cidades" << endl;

	cin >> option;
	switch(option){
	case 1:
		bool setColorEdge;
		setColorEdge = (tempo_total <= tempoNasCidades(cidadesAusar));
		gd.Display(p.getGraph(),cidadesAusar, setColorEdge);
		cin.get();
		Sleep(100000000);
		break;
	case 2:
		if (tempoNasCidades(cidadesAusar) >= tempo_total)
			cout << "Nao  é possivel criar um caminho." << endl;
		else {

			while (!FWShortestPath(p, cidadesAusar, tempo_total)) {
				tempo_total--;
				cout << "\n" << tempo_total << endl;
				cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);
			}
			DisplayGraphFW(p, cidadesAusar);
		}
		break;
	case 3:
		p.CalculaCaminho();
		break;
	default:
		break;
	}


	return 0;
}

/*
int main(){

	int tempo_total;
	string nome = "teste.txt";
	cout << nome << endl;
	File file (nome);
	tempo_total = file.readFile();
	cout << tempo_total << endl;
	Path p;
	//DisplayGraph gd;
	p.createGraph(file);
	//gd.Display(p.getGraph());
	//cin.get();

	vector<Cidade> cidadesAusar = file.viagem.getCidades();

	if( tempo_total <= tempoNasCidades(cidadesAusar))
		cout << "Nao  é possivel criar um caminho." <<endl;
	else{

		vector<Cidade> cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);

		while(!FWShortestPath(p, cidadesAusar,tempo_total)){
				tempo_total--;
				cout << "\n" <<tempo_total << endl;
				cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);
		}
		if( tempo_total <= tempoNasCidades(cidadesAusar) )
			cout << "Nao  é possivel criar um caminho." <<endl;
		else
			DisplayGraphFW(p,cidadesAusar);

	}

	//Knapsackproblemtestar(5);

	//p.PathBranchBound();
	return 0;
}
 */
