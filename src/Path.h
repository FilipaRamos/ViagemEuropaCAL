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
	void createGraph();
	bool verifica(Cidade c, int tempoDisponivel);
	int	calculaTempo();
};



#endif /* SRC_PATH_H_ */
