
/*
 *  Knapsackproblem.cpp
 *
 *  Created on: 24/04/2015
 *      Author: Ines
 */



#include "Knapsackproblem.h"

using namespace std;


/*
 *
 * Resolve o problema da mochila aplicado a Grafos.
 * Seleciona as cidades a serem usadas... Maximizando o tempo e a classificação ...
 * Retorna um vector com as Cidades a serem usadas na construção do grafo.
 *
 */
vector<Cidade> Knapsackproblem(Viagem v, Path p, int tempoMax) {

	vector<Cidade> res;
	//int a[v.getCidades().size()+1][tempoMax+1];

	p.getGraph().setA(new int *[v.getCidades().size() + 1]);

	for (size_t i = 0; i < v.getCidades().size() + 1; ++i) {
		p.getGraph().getA()[i] = new int[tempoMax + 1];
	}

	//INICIALIZAR TUDO A ZERO
	for (size_t i = 0; i < v.getCidades().size() + 1; ++i) {
		for (size_t j = 0; j < tempoMax + 1; ++j) {
			p.getGraph().getA()[i][j] = 0;
		}
	}


	int iMax = 0;
	int jMax = 0;
	vector<pair<int, int> > classificacoes;

	// cria a mochila
	for (size_t i = 0; i <= v.getCidades().size(); ++i) {
		for (size_t j = 0; j <= tempoMax; ++j) {
			if (i == 0) {
				p.getGraph().getA()[i][j] = 0;
			} else {
				if (p.getGraph().getVertexSet().at(i - 1)->getInfo().getTempo() <= j) {
					int dif_tempos = j - p.getGraph().getVertexSet().at(i - 1)->getInfo().getTempo();
					if (p.getGraph().getVertexSet().at(i - 1)->getInfo().getClassificacao() + p.getGraph().getA()[i - 1][dif_tempos] > p.getGraph().getA()[i - 1][j]) {
						p.getGraph().getA()[i][j] =
								p.getGraph().getVertexSet().at(i - 1)->getInfo().getClassificacao()
								+ p.getGraph().getA()[i - 1][dif_tempos];
					} else {
						p.getGraph().getA()[i][j] =
								p.getGraph().getA()[i - 1][j];
					}
				} else {
					p.getGraph().getA()[i][j] = p.getGraph().getA()[i - 1][j];
				}
			}
			pair<int, int> p;
			p.first = i;
			p.second = j;
			classificacoes.push_back(p);
		}
	}

	//encontrar o maximo das classificações

	sort(classificacoes.begin(), classificacoes.end());

	iMax = classificacoes.at(classificacoes.size() - 1).first;
	jMax = classificacoes.at(classificacoes.size() - 1).second;

	//encontrar as cidades a serem usadas.

	size_t j = jMax;
	size_t i = iMax;

	while (i > 0 && j > 0) {
		if (p.getGraph().getA()[i][j] != p.getGraph().getA()[i - 1][j]) {
			res.push_back(p.getGraph().getVertexSet().at(i - 1)->getInfo());
			j -= p.getGraph().getVertexSet().at(i - 1)->getInfo().getTempo();
			i--;
		} else
			i--;
	}

	cout << "\niMax " << iMax <<endl;
	cout << "\njMax " << jMax <<endl;

	cout << "\nVECTOR A-Mochila:\n"<< endl;
	for (size_t i = 0; i <= v.getCidades().size(); ++i) {
		for (size_t j = 0; j <=  tempoMax ; ++j) {
			cout << p.getGraph().getA()[i][j] << " ";
		}
		cout << endl;
	}


	cout << "///////////////////////////////////////////////////////////////////" << endl;

	for (size_t i = 0; i < res.size(); ++i) {
		cout << res[i].getNome() << endl;
	}

	cout << "///////////////////////////////////////////////////////////////////" << endl;

	return res;
}

vector<Cidade> Knapsackproblemtestar(int tempoMax) {

	vector<Cidade> teste;

	Cidade c1("Amesterdam", 7, 1);
	Cidade c2("Paris", 5, 2);
	Cidade c3("Barcelona", 8, 1);
	Cidade c4("Porto", 10, 4);
	Cidade c5("cenas", 9, 3);

	teste.push_back(c1);
	teste.push_back(c2);
	teste.push_back(c3);
	teste.push_back(c4);
	teste.push_back(c5);

	vector<Cidade> res;

	int a[teste.size() + 1][tempoMax + 1];
	int iMax = 0;
	int jMax = 0;

	vector<pair<int, int> > classificacoes;

	for (size_t i = 0; i < teste.size() + 1; ++i) {
		for (size_t j = 0; j < tempoMax + 1; ++j) {
			if (i == 0) {
				a[i][j] = 0;
			} else {
				if (teste.at(i - 1).getTempo() <= j) {
					int dif_tempos = j - teste.at(i - 1).getTempo();
					if ((teste.at(i - 1).getClassificacao()
							+ a[i - 1][dif_tempos]) > a[i - 1][j]) {
						a[i][j] = teste.at(i - 1).getClassificacao()
												+ a[i - 1][dif_tempos];
					} else {
						a[i][j] = a[i - 1][j];
					}
				} else {
					a[i][j] = a[i - 1][j];
				}
			}
			pair<int, int> p;
			p.first = i;
			p.second = j;
			classificacoes.push_back(p);
		}
	}

	for (size_t i = 0; i < teste.size() + 1; ++i) {
		for (size_t j = 0; j < teste.size() + 1; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//encontrar o maximo das classificações

	sort(classificacoes.begin(), classificacoes.end());

	iMax = classificacoes.at(classificacoes.size() - 1).first;
	jMax = classificacoes.at(classificacoes.size() - 1).second;

	cout << iMax << endl;
	cout << jMax << endl;

	cout << res.size() << endl;

	size_t j = jMax;
	size_t i = iMax;

	while (i > 0 && j > 0) {
		if (a[i][j] != a[i - 1][j]) {
			res.push_back(teste.at(i - 1));
			j -= teste.at(i - 1).getTempo();
			i--;
		} else
			i--;
	}

	cout
	<< "///////////////////////////////////////////////////////////////////"
	<< endl;

	for (size_t i = 0; i < res.size(); ++i) {
		cout << res[i].getNome() << endl;
	}

	cout
	<< "///////////////////////////////////////////////////////////////////"
	<< endl;

	return res;

}

int posCidade(Cidade c, Path p) {
	for (size_t i = 0; i < p.getGraph().getVertexSet().size(); ++i) {
		if (p.getGraph().getVertexSet().at(i)->getInfo().getNome()
				== c.getNome()) {
			return i;
		}
	}
}

int tempoNasCidades(vector<Cidade> cidadesAusar) {
	int res = 0;
	for (int i = 0; i < cidadesAusar.size(); ++i) {
		res += cidadesAusar.at(i).getTempo();
	}
	return res;
}

vector<Cidade> ordenaVector(vector<Cidade> cidadesAusar, Path p) {

	vector<Cidade> res;

	for (size_t i = 0; i < p.getGraph().getVertexSet().size(); ++i) {
		for (size_t j = 0; j < cidadesAusar.size(); ++j) {
			if (cidadesAusar.at(j).getNome()
					== p.getGraph().getVertexSet().at(i)->getInfo().getNome()) {
				res.push_back(p.getGraph().getVertexSet().at(i)->getInfo());
			}
		}
	}

	return res;
}

void corrigiroW(Path p){

	for(size_t i =0; i< p.getGraph().getVertexSet().size() ; ++i){
		for(size_t j =0; j< p.getGraph().getVertexSet().size() ; ++j){
			p.getGraph().getW()[i][j] = p.getGraph().edgeCost(i,j);
		}
	}

}

bool FWShortestPath(Path p, vector<Cidade> cidadesAusar, int tempoMax) {

	int tempos = 0;
	int melhorTempo = tempoMax;

	vector<int> melhorsequencia;
	vector<int> inteiroscidades;

	p.getGraph().floydWarshallShortestPath();

	cidadesAusar = ordenaVector(cidadesAusar, p);

	for (size_t i = 0; i < cidadesAusar.size(); ++i) {
		inteiroscidades.push_back(i);
	}

	corrigiroW(p);

	while (std::next_permutation(inteiroscidades.begin(), inteiroscidades.end())) {

		cout << "\nDENTRO DO WHILE!!!\n" << endl;
		tempos = 0;
		tempos += tempoNasCidades(cidadesAusar);

		for (size_t i = 1; i < inteiroscidades.size(); ++i) {
			cout << "\nDENTRO DO FOR!!!\n" << endl;
			tempos +=
					p.getGraph().getW()[posCidade(cidadesAusar.at(i - 1), p)][posCidade(
							cidadesAusar.at(i), p)];

			if (tempos < melhorTempo) {
				cout << "\nDENTRO DO IF!!!\n" << endl;
				melhorsequencia = inteiroscidades;
				melhorTempo = tempos;
				melhorsequencia = inteiroscidades;
				melhorTempo = tempos;
			}

			else {
				cout << "\nDENTRO DO ELSE!!!\n" << endl;
				if (tempos > melhorTempo) {
					cout << "\nDENTRO DO IF2!!!\n" << endl;
					tempos = 0;
					tempos += tempoNasCidades(cidadesAusar);
				}
			}

		}
	}

	return (melhorTempo + p.getGraph().getW()[posCidade(cidadesAusar.at(0), p)][posCidade(cidadesAusar.at(melhorsequencia.size() - 1), p)])
			<= tempoMax;

}

// VER O QUE CONTEM A MATRIX W

/*
        for(size_t i=0; i< p.getGraph().getVertexSet().size(); ++i){
                for(size_t j=0; j<p.getGraph().getVertexSet().size(); ++j){
                        cout <<  p.getGraph().getW()[i][j] << " ";
                }
                cout << endl;
        }
 */


void DisplayGraphFW(Path p, vector<Cidade> cidadesAusar){

	p.getGraph().floydWarshallShortestPath();
	cidadesAusar = ordenaVector(cidadesAusar, p);


	for(size_t i=0; i< cidadesAusar.size(); ++i){
		cout << cidadesAusar.at(i).getNome() << " -> " ;
	}

	cout << cidadesAusar.at(0).getNome() << endl;

}
