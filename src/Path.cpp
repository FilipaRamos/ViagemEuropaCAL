/*
 * Path.cpp
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#include "Path.h"

Path::Path() {
	minimum_bound = 0;
	tempo_total = 0;
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


/*
 * Reduzir a matrix por linha
 */
void Path::ReduzirLinha(int ** matrix){
	vector<int> reducoes_linha;
	/*
	 * Encontra os mínimos de cada linha
	 */
	for (unsigned int i = 0; i < g.getVertexSet().size(); ++i) {
		int minimo_linha = 5000;
		bool infinite = false;
		for (unsigned int j = 0; j < g.getVertexSet().size(); ++j) {
			if (i != j) {
				if(matrix[i][j] != -1){
					if(matrix[i][j] < minimo_linha){
						minimo_linha = matrix[i][j];
						infinite = true;
					}
				}
			}
		}
		if(infinite = false)
			reducoes_linha.push_back(0);
		else
			reducoes_linha.push_back(minimo_linha);
		/*
		*Subtrair os minimos de cada linha
		*/
		for(unsigned int k = 0; k < g.getVertexSet().size(); ++k){
			matrix[i][k] = matrix[i][k] - reducoes_linha[k];
		}

	}
	/*
	 * Atualizar o bound
	 */
	CalculaBound(reducoes_linha);
}

/*
 * Reduzir a matrix por coluna
 */
void Path::ReduzirColuna(int **  matrix){
	vector<int> reducoes_coluna;
	/*
	 * Encontra os mínimos de cada coluna
	 */
	for (unsigned int j = 0; j < g.getVertexSet().size(); j++) {
		int minimo_coluna = 5000;
		bool infinite = false;
		for (unsigned int i = 0; i < g.getVertexSet().size(); i++) {
			if (i != j) {
				if (matrix[i][j] != -1) {
					if (matrix[i][j] < minimo_coluna) {
						minimo_coluna = matrix[i][j];
						infinite = true;
					}
				}
			}
		}
		if (infinite = false)
			reducoes_coluna.push_back(0);
		else
			reducoes_coluna.push_back(minimo_coluna);
		/*
		 *Subtrair os minimos de cada linha
		 */
		for (unsigned int k = 0; k < g.getVertexSet().size(); ++k) {
			matrix[j][k] = matrix[j][k] - reducoes_coluna[k];
		}
	}
	CalculaBound(reducoes_coluna);
}

/*
 * Calcula o bound mínimo
 */
void Path::CalculaBound(vector<int> &v){
	for(unsigned int i = 0; i < v.size(); i++){
		minimum_bound += v[i];
	}
}

int Path::calculaNovoCaminho(int partida, vector<Vertex<Cidade> *> cidades, string &path){
	unsigned int j = 0;
	int tempo_minimo = 5000;
	int indice = 0;
	bool found = false;
	while (j < (cidades.size() - (partida + 1))) {
		if (cidades[partida]->getInfo().getTemposViagem()[j] < tempo_minimo) {
			tempo_minimo = cidades[partida]->getInfo().getTemposViagem()[j];
			indice = partida + (j+1);
			found = true;
		}
		++j;
	}
	if(found == true)
		tempo_total += tempo_minimo;
	path = path + "-->" + cidades[partida]->getInfo().getNome();
	return indice;
}

void Path::CalculaCaminho(){
	vector<Vertex<Cidade> *> cidades = g.getVertexSet();
	string path;
	for(unsigned int i = 0; i < cidades.size(); ++i){
		calculaNovoCaminho(i, cidades, path);
	}
	cout << "path\1: " << path << endl;
	for(unsigned int j = cidades.size(); j > 0; --j){
		calculaNovoCaminho(j, cidades, path);
	}
	cout << "path: " << path << endl;
	cout << "TEMPO_TOTAL: " << tempo_total << endl;
}


/*
 * Utiliza o algoritmo de Branch and Bound para encontrar o caminho mais curto
 * depois de ser aplicada a resolução do problema da mochila
 * Aplicação da fórmula --> minimum_bound(S) = minimum_bound(R) + A(i,j) + y
 */
void Path::PathBranchBound(){
	vector<Vertex<Cidade> *> cidades = g.getVertexSet();
	/*
	 * cálculo da matriz adjacente
	 */
	int matrixA[cidades.size()][cidades.size()];
	/*
	 * criar a matriz adjacente não reduzida
	 */
	for (unsigned int i = 0; i < (cidades.size() - 1); ++i) { // cria a matriz triangular superior
		unsigned int j = 0;
		int posicao = i + 1;
		while (j < (cidades.size() - (i + 1))) {
			matrixA[i][posicao] = g.getVertexSet()[i]->getInfo().getTemposViagem().at(j);
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

	/*
	 * Reduzir a matriz
	 */
	//reduzirLinha(matrixA);
	//reduzirColuna(matrixA);

	/*
	 * Criação da matriz R
	 */
	int matrixR[cidades.size()][cidades.size()];

	for (unsigned int i = 0; i < cidades.size(); ++i) {
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			matrixR[i][j] = matrixA[i][j];
		}
	}

	/*
	 * Criação da matriz S
	 */
	int matrixS[cidades.size()][cidades.size()];

	for (unsigned int i = 0; i < cidades.size(); ++i) {
		for (unsigned int j = 0; j < cidades.size(); ++j) {
			matrixS[i][j] = matrixR[i][j];
		}
	}

	/*
	 * Cálculo das matrizes R e S e cálculo do caminho
	 */
	for (unsigned int linha = 0; linha < cidades.size(); ++linha) {
		unsigned int coluna = 1;
		for (unsigned int i = 0; i < cidades.size(); ++i) { // a matriz S torna-se a matriz R
			for (unsigned int j = 0; j < cidades.size(); ++j) {
				matrixR[i][j] = matrixS[i][j];
			}
		}
		while (coluna <= (cidades.size() - (linha + 1))) {
			if (linha != coluna && coluna > linha) {
				/*
				 * Início do caminho
				 */
				for (unsigned int j = 0; j < cidades.size(); ++j) {
					matrixS[linha][j] = -1;
				}
				matrixS[coluna][linha] = -1;
				for (unsigned int k = 0; k < cidades.size(); ++k) {
					matrixS[k][coluna] = -1;
				}

				vector<int> rL;
				vector<int> rC;

				/*
				 * Reduzir por linha
				 */
				int minimo_linha = 50;
				bool minimoL = false;
				for (unsigned int i = 0; i < cidades.size(); ++i) {
					for (unsigned int j = 0; j < cidades.size(); ++j) {
						if (matrixS[i][j] != -1 || matrixS[i][j] != 0) {
							if (matrixS[i][j] < minimo_linha) {
								minimo_linha = matrixS[i][j]; // encontrar o mínimo de cada linha
								minimoL = true;
							}
						}
					}
					if (minimoL == false)
						rL.push_back(0);
					else
						rL.push_back(minimo_linha);
					minimoL = false;
				}
				/*
				 * Subtrair a redução das linhas
				 */
				int kl = 0;
				for (unsigned int i = 0; i < cidades.size(); ++i) {
					for (unsigned int j = 0; j < cidades.size(); ++j) {
						if (matrixS[i][j] != -1) {
							int n = rL[kl];
							if (rL[kl] != 0) {
								matrixS[i][j] = matrixS[i][j] - n; // subtrair a redução
							}
						}
					}
					kl++;
				}
				/*
				 * Reduzir por coluna
				 */
				int minimo_coluna = 50;
				bool minimoC = false;
				for (unsigned int j = 0; j < cidades.size(); ++j) {
					for (unsigned int i = 0; i < cidades.size(); ++i) {
						if (matrixS[i][j] != -1) {
							if (matrixS[i][j] < minimo_coluna) {
								minimo_coluna = matrixS[i][j]; // encontrar o mínimo de cada coluna
								minimoC = true;
							}
						}
					}
					if (minimoC == false)
						rC.push_back(0);
					else
						rC.push_back(minimo_coluna);
					minimoC = false;
				}
				/*
				 * Subtrair a redução por coluna
				 */
				int cl = 0;
				for (unsigned int j = 0; j < cidades.size(); ++j) {
					for (unsigned int i = 0; i < cidades.size(); ++i) {
						if (matrixS[i][j] != -1) {
							int n = rC[cl];
							if (rC[cl] != 0) {
								matrixS[i][j] = matrixS[i][j] - n; // subtrair a redução
							}
						}
					}
					cl++;
				}

				cout << "( " << linha << " --> " << coluna << ")" << endl;
				for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
					for (unsigned int j = 0; j < cidades.size(); ++j) {
						cout << matrixS[i][j] << " ";
					}
					cout << endl;
				}
				cout << "//////////////////////" << endl;
				/*
				 *Atualização do minimum_bound
				 */
				for (unsigned int i = 0; i < rL.size(); ++i) {
					minimum_bound += rL[i];
				}

				for (unsigned int j = 0; j < rC.size(); ++j) {
					minimum_bound += rC[j];
				}

				minimum_bound += matrixA[linha][coluna];

				minimum_cost.push_back(minimum_bound);

				cout << "#minimum_bound --> " << minimum_bound << endl;

				for (unsigned int i = 0; i < cidades.size(); ++i) {
					for (unsigned int j = 0; j < cidades.size(); ++j) {
						matrixS[i][j] = matrixR[i][j];
					}
				}

				coluna++;
			}
		}
		int minimo = minimum_cost[0];
		for (unsigned int i = 1; i <= minimum_cost.size(); ++i) {
			cout << "custo em dias: " << minimum_cost[i] << endl;
			if (minimum_cost[i] < minimo) {
				minimo = minimum_cost[i];
			}
		}
	}
}

