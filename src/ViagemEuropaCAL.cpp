//============================================================================
// Name        : ViagemEuropaCAL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Files.h"
#include "Cidade.h"
#include "Graph.h"
#include "Viagem.h"
#include "ShowGraph/DisplayGraph.h"

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
	return 0;
}

