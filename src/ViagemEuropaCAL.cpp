
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
	Path p;
	//DisplayGraph gd;
	p.createGraph(file);
	//gd.Display(p.getGraph());
	//cin.get();
	//Knapsackproblem(file.viagem, p);
	p.PathBranchBound();
	return 0;
}

