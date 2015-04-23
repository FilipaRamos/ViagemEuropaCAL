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

using namespace std;

class Cidade{
	string nome; // nome da cidade
	int classificacao; // classifica��o atribuida � cidade
	int tempo; // tempo que quer passar na cidade
	list<int> distancias; // lista que guarda os tempos entre as cidades

public:
	Cidade(string n, int c, int t);
	string getNome();
	int getClassificacao();
	int getTempo();
	list<int>& getDistancias();
	void addDistancia(int d);
};


#endif /* CIDADE_H_ */
