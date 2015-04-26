/*
 * Path.h
 *
 *  Created on: 22/04/2015
 *      Author: Filipa
 */

#ifndef SRC_PATH_H_
#define SRC_PATH_H_

#include "Path.h"
#include "Cidade.h"
#include "Viagem.h"
#include "Files.h"
#include "Graph.h"

static int n;

class Path{
	Graph<Cidade> g;
	int minimum_bound;
	vector<int> minimum_path; // guarda a sequência do caminho mais curto
	vector<int> minimum_cost; // guarda o custo do caminho
public:
	Path();
	Graph<Cidade>& getGraph(){return g;};
	int returnN(){return n;};
	void createGraph(File f);
	void createGraphtestar();
	bool verifica(Cidade c, int tempoDisponivel);
	int	calculaTempo();
	void PathBranchBound();
};



#endif /* SRC_PATH_H_ */
