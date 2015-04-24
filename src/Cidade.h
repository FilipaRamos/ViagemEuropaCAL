/*
 * Cidade.h
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#ifndef CIDADE_H_
#define CIDADE_H_

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

class Cidade{
	string nome; // nome da cidade
	int classificacao; // classificação atribuida à cidade
	int tempo; // tempo que quer passar na cidade
	vector<int> tempos_viagem; // lista que guarda os tempos entre as cidades

public:
	Cidade(string n, int c, int t);
	string getNome();
	int getClassificacao();
	int getTempo();
	vector<int>& getTemposViagem();
	void addTempoViagem(int d);
	bool operator == (Cidade c);
	void ordenarVector();
};


#endif /* CIDADE_H_ */
