/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path() {}

/*
 * Calcula o tempo de permanencia de todas as cidades que j� se encontram no grafo
 */
int Path::calculaTempo() {
	int res = 0;
	for (size_t i = 0; i < g.getVertexSet().size(); ++i) {
		for (size_t j = 0; j < g.getVertexSet().at(i)->getAdj().size(); ++j) {
			res += g.getVertexSet().at(i)->getInfo().getTempo()
					+ g.getVertexSet().at(i)->getAdj().at(j).getWeight();
		}
	}
	cout << res << endl;
	return res;
}

/*
 * Verifica se o tempo � excedido ou n�o
 */
bool Path::verifica(Cidade c, int tempoDisponivel) {
	int tempo_novaCidade = calculaTempo() + c.getTempo();

	if (tempo_novaCidade < calculaTempo()) {
		return true;
	}

	else
		return false;
}

/*
 * Fun��o na qual vai ser criado o grafo com as cidades
 */
void Path::createGraph() {

	File f("teste.txt");
	int tempoDisponivel = f.readFile();
	vector<Cidade> cidades = f.viagem.getCidades();

	for (size_t i = 0; i < cidades.size(); ++i) {
		g.addVertex(cidades[i]);
	}

	for (size_t i = 0; i < cidades.size(); ++i) {
		unsigned int j = 0;
		while (j < (cidades.size() - (i + 1))) {
			g.addEdge(cidades[i], cidades[j+1], cidades[i].getTemposViagem()[i]);
			++j;
		}
	}

/*
	/// S� PARA TESTAR SE O GRAFO EST� A SER BEM CONSTRUIDO
	vector<Vertex<Cidade> *> vetor = g.getVertexSet();
	for(int j = 0; j < vetor.size(); ++j){
		cout << vetor[j] << endl;
	}
*/
}


void Path::createGraphtestar() {

	File f("teste.txt");
		int tempoDisponivel = f.readFile();
		vector<Cidade> cidades = f.viagem.getCidades();

		for(size_t k=0; k<3; k++){
			cout << cidades[0].getTemposViagem().at(k) <<endl;
		}

		for (size_t i = 0; i < cidades.size(); ++i) {
			g.addVertex(cidades[i]);
			cout << g.getVertexSet()[i]->getInfo().getNome() << endl;
		}

		for (size_t i = 0; i < cidades.size(); ++i) {
			unsigned int j = 0;
			while (j < (cidades.size() - (i + 1))) {
				g.addEdge(cidades[i], cidades[j+1], cidades[i].getTemposViagem()[j]);
				cout << g.getVertexSet().at(i)->getAdj().at(j).getWeight()<< endl;
				++j;
			}
		}

}

/*
 * Utiliza o algoritmo de Branch and Bound para encontrar o caminho mais curto
 * depois de ser aplicada a resolu��o do problema da mochila
 */
void Path::PathBranchBound(){

}

