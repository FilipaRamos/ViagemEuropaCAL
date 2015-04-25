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

class Path{
	Graph<Cidade> g;
public:
	Path();
	Graph<Cidade>& getGraph(){return g;};
	void createGraph(File f);
	void createGraphtestar();
	bool verifica(Cidade c, int tempoDisponivel);
	int	calculaTempo();
	void PathBranchBound(File f);
};



#endif /* SRC_PATH_H_ */
