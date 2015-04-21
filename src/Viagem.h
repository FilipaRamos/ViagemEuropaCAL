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
#include "Cidade.h"

using namespace std;

class Viagem{
	vector<Cidade> cidades; // vetor onde s�o guardadas as cidades

public:
	vector<Cidade> getCidades();
};

#endif /* VIAGEM_H_ */
