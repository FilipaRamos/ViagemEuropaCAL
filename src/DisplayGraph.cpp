/*
 * DisplayGraph.cpp
 *
 *  Created on: 23/04/2015
 *      Author: Mariana
 */

#include "DisplayGraph.h"
#include "graphviewer.h"

void DisplayGraph::Display() {
	// TODO Auto-generated constructor stub
	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->createWindow(600, 600);

	gv->defineVertexColor(BLUE);

	gv->defineEdgeColor(BLACK);

}


