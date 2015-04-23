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

list<int>& Cidade::getTemposViagem(){
	return tempos_viagem;
}

void Cidade::addDistancia(int d){
	/*
	 * vai permitir que as distâncias fiquem ordenadas
	 * segundo a ordem em que foram introduzidas no txt
	 */
	tempos_viagem.push_back(d);
}

bool Cidade::operator == (Cidade c){
	if(nome == c.getNome())
		return true;
	return false;
}
