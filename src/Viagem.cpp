/*
 * Viagem.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */

#include "Viagem.h"

using namespace std;

<<<<<<< HEAD
Viagem::Viagem(){

}
=======
Viagem::Viagem(){}
>>>>>>> origin/master

vector<Cidade>& Viagem::getCidades(){
	return cidades;
}

void Viagem::imprimirCidades(){
	for(unsigned int i = 0; i < cidades.size(); i++){
		cout << cidades[i].getNome() << endl;
		cout << cidades[i].getTempo() << endl;
	}
}

