/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path() {
	minimum_bound = 0;
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
 * Aplicação da fórmula --> minimum_bound(S) = minimum_bound(R) + A(i,j) + y
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
	for (unsigned int i = 0; i < (cidades.size() - 1); ++i) { // cria a matriz triangular superior
		unsigned int j = 0;
		int posicao = i + 1;
		while (j < (cidades.size() - (i + 1))) {
			matrixA[i][posicao] =
					g.getVertexSet()[i]->getInfo().getTemposViagem().at(j);
			posicao++;
			j++;
		}
	}

	for (unsigned int k = 1; k < cidades.size(); ++k) { // cria a matriz triangular inferior
		for (unsigned int l = 0; l < k; ++l) {
			matrixA[k][l] = matrixA[l][k];
		}
	}

	for (unsigned int i = 0; i < cidades.size(); ++i) { // cria a diagonal
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			if (i == j)
				matrixA[i][j] = -1; // -1 representa o infinito (viagem do nódulo para si próprio)
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
	vector<int> reducoes_linha; // guarda as reduções de linha para mais tarde somá-las e obter o minimum bound
	vector<int> reducoes_coluna; // guarda as reduções de coluna para mais tarde somá-las e obter o minimum bound

	/*
	 * Reduzir por linha
	 */
	int minimo_linha;
	for (unsigned int i = 0; i < cidades.size(); ++i) {
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			if (i == 0 && j == 1)
				minimo_linha = matrixA[i][j];
			if (i != j) {
				if (matrixA[i][j] < minimo_linha) {
					minimo_linha = matrixA[i][j]; // encontrar o mínimo de cada linha
				}
			}
		}
		reducoes_linha.push_back(minimo_linha);
	}

	/*
	 * Subtrair a redução das linhas
	 */
	int k = 0;
	for (unsigned int i = 0; i < cidades.size(); ++i) {
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			if (i != j) {
				int n = reducoes_linha[k];
				matrixA[i][j] = matrixA[i][j] - n; // subtrair a redução
			}
		}
		k++;
	}

	/*
	 * Reduzir por coluna
	 */
	int minimo_coluna;
	for (unsigned int j = 0; j < cidades.size(); ++j) {
		for (unsigned int i = 0; i < cidades.size(); ++i) {
			if (i == 1 && j == 0) {
				minimo_coluna = matrixA[i][j];
			}
			if (i != j) {
				if (matrixA[i][j] < minimo_coluna) {
					minimo_coluna = matrixA[i][j]; // encontrar o mínimo de cada coluna
				}
			}
		}
		reducoes_coluna.push_back(minimo_coluna);
	}

	/*
	 * Subtrair a redução por coluna
	 */
	int l = 0;
	for (unsigned int j = 0; j < cidades.size(); ++j) {
		for (unsigned int i = 0; i < cidades.size(); ++i) {
			if (i != j) {
				int c = reducoes_coluna[l];
				matrixA[i][j] = matrixA[i][j] - c; // subtrair a redução
			}
		}
		l++;
	}

	cout << "::::::::::::::::" << endl;

	for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}

	/*
	 *Cálculo do minimum_bound
	 */
	for (unsigned int i = 0; i < reducoes_linha.size(); ++i) {
		minimum_bound += reducoes_linha[i];
	}

	for (unsigned int j = 0; j < reducoes_coluna.size(); ++j) {
		minimum_bound += reducoes_coluna[j];
	}

	cout << "#minimum_bound --> " << minimum_bound << endl;

	/*
	 * Criação da matriz R
	 */

	int matrixR[cidades.size()][cidades.size()];

	for (unsigned int i = 0; i < cidades.size(); ++i) {
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			matrixR[i][j] = matrixA[i][j];
		}
	}

	cout << "::::::::::::::::" << endl;

	for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			cout << matrixR[i][j] << " ";
		}
		cout << endl;
	}


	/*
	 * Início do caminho
	 */
	for(unsigned int i = 0; i < 1; ++i){ // anular o caminho realizado
		for(unsigned int j = 0; j < cidades.size(); ++j){
			matrixA[i][j] = -1;
		}
	}

	for(unsigned int j = 0; j < 1; ++j){


	}

}

