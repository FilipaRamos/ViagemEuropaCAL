/*
 *  Knapsackproblem.cpp
 *
 *  Created on: 24/04/2015
 *      Author: Ines
 */



#include "Knapsackproblem.h"

using namespace std;

vector<Cidade> Knapsackproblem(Viagem v, Path p){

	vector<Cidade> res;

	int a[v.getCidades().size()+1][p.calculaTempo()+1];
	int iMax = 0;
	int jMax = 0;
	vector<pair<int,int> > classificacoes;

	for(size_t i =0; i < v.getCidades().size()+1; ++i){
		for(size_t j=0; j < p.calculaTempo()+1; ++j){
			if(i==0){
				a[i][j] = 0;
			}
			else{
				if(p.getGraph().getVertexSet().at(i-1)->getInfo().getTempo() <= j){
					int dif_tempos = p.getGraph().getVertexSet().at(i-1)->getInfo().getTempo() - j;
					if( p.getGraph().getVertexSet().at(i-1)->getInfo().getClassificacao() + a[i-1][dif_tempos] > a[i-1][j]){
						a[i][j] = p.getGraph().getVertexSet().at(i-1)->getInfo().getClassificacao() + a[i-1][dif_tempos];
					}
					else {
						a[i][j] = a[i-1][j];
					}
				}
				else
				{
					a[i][j] = a[i-1][j];
				}
			}
			pair<int,int> p;
			p.first = i;
			p.second = j;
			classificacoes.push_back(p);
		}
	}


	//encontrar o maximo das classificações
	//TODO: MOSTRAR AO TRINDADE PARA CONFIRMAR

	sort(classificacoes.begin(), classificacoes.end());

	iMax = classificacoes.at(classificacoes.size() -1).first;
	jMax = classificacoes.at(classificacoes.size() -1).second;


	for(size_t i=iMax ; i > 0; --i){
		for(size_t j=jMax; j > 0;){
			if(a[i][j] != a[i-1][j]){
				res.push_back(p.getGraph().getVertexSet().at(i-1)->getInfo());
				j -= p.getGraph().getVertexSet().at(i-1)->getInfo().getTempo();
			}
		}
	}

	return res;

}

vector<Cidade> Knapsackproblemtestar(){

	vector<Cidade> teste;

	Cidade c1("Amesterdam", 10, 4);
	Cidade c2("Paris", 7, 1);
	Cidade c3("Barcelona", 8, 4);
	Cidade c4("Porto", 10, 4);
	Cidade c5("cenas", 9, 3);

	teste.push_back(c1);
	teste.push_back(c2);
	teste.push_back(c3);
	teste.push_back(c4);
	teste.push_back(c5);

	vector<Cidade> res;

	int a[teste.size()+1][teste.size()+1];
	int iMax = 0;
	int jMax = 0;

	vector<pair<int,int> > classificacoes;

	//cout << res.size() << endl;

	for(size_t i=0; i < teste.size()+1 ; ++i){
		for(size_t j=0; j < teste.size()+1 ; ++j){
			if(i==0){
				a[i][j] = 0;
			}
			else{
				if(teste.at(i-1).getTempo() <= j){
					int dif_tempos = j - teste.at(i-1).getTempo();
					if(( teste.at(i-1).getClassificacao() + a[i-1][dif_tempos] ) > a[i-1][j]){
						a[i][j] = teste.at(i-1).getClassificacao() + a[i-1][dif_tempos];
					}
					else {
						a[i][j] = a[i-1][j];
					}
				}
				else
				{
					a[i][j] = a[i-1][j];
				}
			}
			pair<int,int> p;
			p.first = i;
			p.second = j;
			classificacoes.push_back(p);
		}
	}


	for(size_t i=0; i<teste.size()+1; ++i){
		for(size_t j=0; j<teste.size()+1; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}



	//encontrar o maximo das classificações
	//TODO: MOSTRAR AO TRINDADE PARA CONFIRMAR

	sort(classificacoes.begin(), classificacoes.end());

	iMax = classificacoes.at(classificacoes.size()-1).first;
	jMax = classificacoes.at(classificacoes.size()-1).second;

	cout << iMax << endl;
	cout << jMax << endl;


	for(size_t i=0; i<res.size(); ++i){
		cout << res.size() << endl;
		cout << res.at(i).getNome() << endl;
	}

	for(size_t i=iMax ; i > 0; --i){
		for(size_t j=jMax; j > 0;){
			if(a[i][j] != a[i-1][j]){
				res.push_back(teste.at(i-1));
				j -= teste.at(i-1).getTempo();
			}
		}
	}


	return res;

}

