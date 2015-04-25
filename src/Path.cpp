/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path() {}

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
void Path::createGraph(File f) {

	vector<Cidade> cidades = f.viagem.getCidades();

	for (size_t i = 0; i < cidades.size(); ++i) {
		g.addVertex(cidades[i]);
	}

	for (size_t i = 0; i < cidades.size(); ++i) {
		unsigned int j = 0;
		while (j < (cidades.size() - (i + 1))) {
			g.addEdge(cidades[i], cidades[i+1],
					cidades[i].getTemposViagem()[j]);
			++j;
		}
	}


}


void Path::createGraphtestar() {

	File f("teste.txt");
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
				g.addEdge(cidades[i], cidades[i+1], cidades[i].getTemposViagem()[j]);
				cout << g.getVertexSet().at(i)->getAdj().at(j).getWeight()<< endl;
				++j;
			}
		}

}

/*
 * Utiliza o algoritmo de Branch and Bound para encontrar o caminho mais curto
 * depois de ser aplicada a resolução do problema da mochila
 */
void Path::PathBranchBound(){
	vector<Vertex<Cidade> *> cidades = g.getVertexSet();
	/*
	 * cálculo do minimum bound e da matriz adjacente
	 */
	int matrixA[cidades.size()][cidades.size()];

	/*
	 * criar a matriz adjacente não reduzida
	 */
	for(unsigned int i = 0; i < (cidades.size()-1); ++i){ // cria a matriz triangular superior
		unsigned int j = 0;
		int posicao = i + 1;
		while(j < (cidades.size()-(i+1))){
			matrixA[i][posicao] = g.getVertexSet()[i]->getInfo().getTemposViagem().at(j);
			posicao++;
			j++;
		}
	}

	for(unsigned int k = 1; k < cidades.size(); ++k){ // cria a matriz triangular inferior
		for(unsigned int l = 0; l < k; ++l){
			matrixA[k][l] = matrixA[l][k];
		}
	}

	for (unsigned int i = 0; i < cidades.size(); ++i) { // cria a diagonal
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			if(i == j)
				matrixA[i][j] = -1; // 0 representa o infinito (viagem do nódulo para si próprio)
		}
	}


	for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}


	/*
	 * Reduzir a matrix
	 */
	vector<int> reducoes; // guarda as reduções para mais tarde somá-las e obter o minimum bound

	/*
	 * Reduzir por linha
	 */
	int minimo;
	for (unsigned int i = 0; i < cidades.size(); ++i) { // encontrar o mínimo de cada linha
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			if(i == 0 && i != j)
				minimo = matrixA[i][j];
			if (i != j) {
				if (matrixA[i][j] < minimo){
					minimo = matrixA[i][j];
				}
			}
		}
		reducoes.push_back(minimo);
	}

	cout << reducoes.size() << endl;
	for(unsigned int i = 0; i < reducoes.size();++i)
		cout << reducoes[i] << endl;



}

