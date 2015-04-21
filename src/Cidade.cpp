/*
 * Cidade.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#include "Cidade.h"

Cidade::Cidade(string n, int c, int t){
	nome = n;
	classificacao = c;
	tempo = t;
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

void Cidade::addDistancia(int d){
	/*
	 * vai permitir que as dist�ncias fiquem ordenadas
	 * segundo a ordem em que foram introduzidas no txt
	 */
	distancias.push_back(d);  /////// VERIFICAR ESTE PUSH!!!!
}
