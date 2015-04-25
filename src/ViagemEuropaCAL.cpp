
#include <iostream>
#include "Files.h"
#include "Cidade.h"
#include "Graph.h"
#include "Viagem.h"

#include "ShowGraph/DisplayGraph.h"
#include "Path.h"
#include "ShowGraph/DisplayGraph.h"
#include "Knapsackproblem.h"

using namespace std;
int main(){

	int tempo_total;
	string nome = "teste.txt";
	cout << nome << endl;
	File file (nome);
	tempo_total = file.readFile();
	cout << tempo_total << endl;
	Graph<Cidade> g;
	DisplayGraph gd;
	gd.Display(g);
	cin.get();
	Path p;
	p.createGraph(file);
	Knapsackproblem(file.viagem, p);
	cout << "pintou!" << endl;
	//DisplayGraph g;
	//g.Display();
	//cin.get();
	return 0;
}

