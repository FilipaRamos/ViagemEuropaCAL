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

	/*
	 *Cálculo do minimum_bound inicial
	 */
	for (unsigned int i = 0; i < reducoes_linha.size(); ++i) {
		minimum_bound += reducoes_linha[i];
	}

	for (unsigned int j = 0; j < reducoes_coluna.size(); ++j) {
		minimum_bound += reducoes_coluna[j];
	}

	cout << "#minimum_bound --> " << minimum_bound << endl;

	int bound_inicial = minimum_bound;

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

	/*
	 * Cálculo das matrizes R e S e cálculo do caminho
	 */
	for (unsigned int linha = 0; linha < cidades.size(); ++linha) {
		unsigned int coluna = 1;
		while(coluna <= (cidades.size()-(linha+1))) {
			/*
			 * Início do caminho
			 */
			for (unsigned int j = 0; j < cidades.size(); ++j) {
				matrixR[linha][j] = -1;
			}
			matrixR[coluna][linha] = -1;
			for (unsigned int k = 0; k < cidades.size(); ++k) {
				matrixR[k][coluna] = -1;
			}

			vector<int> rL;
			vector<int> rC;
			/*
			 * Reduzir por linha
			 */
			minimo_linha = 50;
			bool minimoL = false;
			for (unsigned int i = 0; i < cidades.size(); ++i) {
				for (unsigned int j = 0; j < cidades.size(); ++j) {
					if (matrixR[i][j] != -1 || matrixR[i][j] != 0) {
						if (matrixR[i][j] < minimo_linha) {
							minimo_linha = matrixR[i][j]; // encontrar o mínimo de cada linha
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
					if (matrixR[i][j] != -1) {
						int n = rL[kl];
						if (rL[kl] != 0) {
							matrixR[i][j] = matrixR[i][j] - n; // subtrair a redução
						}
					}
				}
				kl++;
			}
			/*
			 * Reduzir por coluna
			 */
			minimo_coluna = 50;
			bool minimoC = false;
			for (unsigned int j = 0; j < cidades.size(); ++j) {
				for (unsigned int i = 0; i < cidades.size(); ++i) {
					if (matrixR[i][j] != -1) {
						if (matrixR[i][j] < minimo_coluna) {
							minimo_coluna = matrixR[i][j]; // encontrar o mínimo de cada coluna
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
					if (matrixR[i][j] != -1) {
						int n = rC[cl];
						if (rC[cl] != 0) {
							matrixR[i][j] = matrixR[i][j] - n; // subtrair a redução
						}
					}
				}
				cl++;
			}

			cout << "( " << linha << " --> " << coluna << ")" << endl;
			for (unsigned int i = 0; i < cidades.size(); ++i) { // testar se a matriz está a ser bem construída
				for (unsigned int j = 0; j < cidades.size(); ++j) {
					cout << matrixR[i][j] << " ";
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
					matrixR[i][j] = matrixA[i][j];
				}
			}

			coluna++;
		}

		for(unsigned int i = 0; i < minimum_cost.size(); ++i){
			cout << "custo em dias: " << minimum_cost[i] << endl;
		}

		minimum_bound = bound_inicial;

	}

}

