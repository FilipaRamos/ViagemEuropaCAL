/*
 * DisplayGraph.h
 *
 *  Created on: 23/04/2015
 *      Author: Mariana
 */

#ifndef SRC_DISPLAYGRAPH_H_
#define SRC_DISPLAYGRAPH_H_

#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../Cidade.h"
#include "../Graph.h"
#include "graphviewer.h"


class DisplayGraph {
	GraphViewer *gv;
public:
	DisplayGraph();
	GraphViewer getGraphViewer() { return *gv; };
	void DisplayInitialG(Graph<Cidade> gc, vector<Cidade> cidadesAusar, bool setColorEdge);
	GraphViewer *DisplayPath(Graph<Cidade> gc, vector<Cidade> cidadesAusar, bool setColorEdge);
	GraphViewer *DisplayBranchBound(Graph<Cidade> gc , vector<Cidade> mininum_Path);
	void closeDisplay();
};

#endif /* SRC_DISPLAYGRAPH_H_ */
