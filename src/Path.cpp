/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path(){}

/*
 * Calcula o tempo de permanencia de todas as cidades que já se encontram no grafo
 */
int	Path::calculaTempo(){
	int res = 0;
	for(size_t i=0; i<g.getVertexSet().size(); ++i){
		res += g.getVertexSet().at(i)->getInfo().getTempo();
		// FALTA SOMAR OS TEMPOS DE VIAGEM ENTRE AS CIDADES
	}
	return res;
}

/*
 * Verifica se o tempo é excedido ou não
 */
bool Path::verifica(Cidade c, int tempoDisponivel){
	int tempo_novaCidade = calculaTempo() + c.getTempo();

	if(tempo_novaCidade < calculaTempo()){
		return true;
	}

	else return false;
}

/*
 * Função na qual vai ser criado o grafo com as cidades
 */
void Path::createGraph(){

	File f("teste.txt");
	int tempoDisponivel = f.readFile();
	vector<Cidade> cidades = f.viagem.getCidades();
	int class_max = 10;
	g.addVertex(cidades[0]); // adicionar a cidade de partida
	int tempo_utilizado = calculaTempo();

	while (tempo_utilizado < tempoDisponivel) { // enquanto houver tempo disponível adicionar vértices
		for (unsigned int i = 1; i <= cidades.size(); ++i) {
			if (cidades[i].getClassificacao() == class_max) {
				g.addVertex(cidades[i]);
			}
		}
		class_max--;

	}


}


