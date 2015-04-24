/*
 *  Knapsackproblem.cpp
 *
 *  Created on: 24/04/2015
 *      Author: Ines
 */

#include <algorithm>
#include <vector>
#include "Viagem.h"


vector<Cidade> Knapsackproblem(){

	Viagem v = new Viagem();
	Path p = new Path();

	vector<Cidade> res;

	int a[v.getCidades().size()][p.calculaTempo()];
	int iMax = 0;
	int jMax = 0;
	vector<pair<int,int> > classificacoes;

	for(size_t i =0; i < v.getCidades().size(); ++i){
		for(size_t j=0; j < p.calculaTempo(); ++j){
			if(i==0){
				a[i][j] = 0;
			}
			else{
				if(p.getGraph().getVertexSet().at(i-1)->getInfo().getTempo() >= j){
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


	for(size_t i = iMax ; i > 0; --i){
		for(size_t j=jMax; j > 0;){
			if(a[i][j] != a[i-1][j]){
				res.push_back(p.getGraph().getVertexSet().at(i-1)->getInfo());
				j -= p.getGraph().getVertexSet().at(i-1)->getInfo().getTempo();
			}
		}
	}

	return res;

}


