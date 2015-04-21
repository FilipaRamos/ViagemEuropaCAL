/*
 * Cidade.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#include "Cidade.h"

Cidade::Cidade(string n, int c, int t, list<int> d){
	nome = n;
	classificacao = c;
	tempo = t;
	distancias = d;
}

string Cidade::getNome(){
	return nome;
}

int Cidade::getClassificacao(){
	return classificacao;
}

int Cidade::getTempo(){
	return tempo;
}

list<int> Cidade::getDistancias(){
	return distancias;
}
