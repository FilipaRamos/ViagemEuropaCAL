
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
	int imprimir;
	string nome;
	DisplayGraph gd;
	GraphViewer * g;

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
	vector<Cidade> mininum_Path = p.getMinimumPath();

	cout << " Opções: " << endl;
	cout << " 1. Visualizar grafo inicial" << endl;
	cout << " 2. Calcular as cidades a visitar" << endl;
	cout << " 3. Calcular o tempo que demoraria a visitar todas as cidades" << endl;
	cout << " 4. Visualizar grafo Branch and Bound" << endl;

	cin >> option;
	switch(option){
	case 1:
		bool setColorEdge;
		setColorEdge = (tempo_total <= tempoNasCidades(cidadesAusar));
		gd.DisplayInitialG(p.getGraph(),cidadesAusar, setColorEdge);
		cin.get();
		Sleep(10000);
		gd.closeDisplay();
		break;
	case 2:
		if (tempoNasCidades(cidadesAusar) >= tempo_total)
			cout << "Nao  é possivel criar um caminho." << endl;
		else {
			while (!FWShortestPath(p, cidadesAusar, tempo_total)) {
				if( tempo_total <= tempoNasCidades(cidadesAusar) ){
					cout << "Nao  é possivel criar um caminho." <<endl;
					return 0;
				}
				tempo_total--;
				cout << "\n" << tempo_total << endl;
				cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);
			}
			cout << "Imprimir: " << endl;
			cout << "1. Consola" << endl;
			cout << "2. GraphViewer" << endl;
			cin >> imprimir;
			if(imprimir == 1)
				DisplayGraphFW(p, cidadesAusar);
			else if (imprimir == 2){
				g = gd.DisplayPath(p.getGraph(), cidadesAusar, setColorEdge);
				cin.get();
				Sleep(100000);
				//g->closeWindow();
				gd.closeDisplay();
			}
			else
				cout << "Erro! Opção Inválida!" << endl;

		}
		break;
	case 3:
		p.CalculaCaminho();
		break;

	case 4:
		gd.DisplayBranchBound(p.getGraph(), mininum_Path);
		cin.get();
		Sleep(10000);
		gd.closeDisplay();
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
	bool parar = false;
	//gd.Display(p.getGraph());
	//cin.get();

	vector<Cidade> cidadesAusar = file.viagem.getCidades();

	if( tempo_total <= tempoNasCidades(cidadesAusar))
		cout << "Nao  é possivel criar um caminho." <<endl;
	else{

		vector<Cidade> cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);

		while(!FWShortestPath(p, cidadesAusar,tempo_total) && !parar){
			if( tempo_total <= tempoNasCidades(cidadesAusar) ){
				parar = true;
			}
			else {
				tempo_total--;
				cout << "\n" <<tempo_total << endl;
				cidadesAusar = Knapsackproblem(file.viagem, p, tempo_total);
			}

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
