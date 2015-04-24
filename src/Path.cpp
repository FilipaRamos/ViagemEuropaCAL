/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path() {
}

/*
 * Calcula o tempo de permanencia de todas as cidades que já se encontram no grafo
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
 * Verifica se o tempo é excedido ou não
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
 * Função na qual vai ser criado o grafo com as cidades
 */
void Path::createGraph() {

	File f("teste.txt");
	int tempoDisponivel = f.readFile();
	vector<Cidade> cidades = f.viagem.getCidades();
	g.addVertex(cidades[0]); // adicionar a cidade de partida
	cidades[0].ordenarVector();
	unsigned int j = 0;

	for (size_t i = 1; i <= cidades.size(); ++i) {
		cidades[i].ordenarVector();
		g.addVertex(cidades[i]);
		while (j < (cidades.size() - (i + 1))) {
			g.addEdge(cidades[i - 1], cidades[i], cidades[i - 1].getTemposViagem()[i - 1]);
			++j;
		}
	}
}

	/*
	 * utiliza o algoritmo de Branch and Bound para encontrar o caminho mais curto
	 * depois de ser aplicada a resolução do problema da mochila
	 */
void Path::PathBranchBound(){

}

