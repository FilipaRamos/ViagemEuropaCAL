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
public:
	DisplayGraph();
	void Display(Graph<Cidade> gc);
	int StringInt(string st);
};

#endif /* SRC_DISPLAYGRAPH_H_ */
