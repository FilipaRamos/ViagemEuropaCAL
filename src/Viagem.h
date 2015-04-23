/*
 * Viagem.h
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#ifndef VIAGEM_H_
#define VIAGEM_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Cidade.h"

using namespace std;

class Viagem{
	Graph<Cidade> g;
	vector<Cidade> cidades; // vetor onde são guardadas as cidades

public:
	Viagem();
	vector<Cidade>& getCidades();
	void imprimirCidades();
};

#endif /* VIAGEM_H_ */
