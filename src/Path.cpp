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
			g.addEdge(cidades[i], cidades[i + 1],
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
 * Reduz matrizes
 * --> utilizada no Branch and Bound
 */
void Path::reduzMatriz(int matrix[][]){
	vector<int> reducoes; // guarda as reduções para mais tarde somá-las e obter o minimum bound

	/*
	 * Reduzir por linha
	 */
	for(int i = 0; i < sizeof(matrix[0]); ++i){

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
	int minimum_bound = 0;
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
				matrixA[i][j] = -1; // -1 representa o infinito (viagem do nódulo para si próprio)
		}
	}

	/*
	for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}
*/

	/*
	 * Reduzir a matrix
	 */



}

