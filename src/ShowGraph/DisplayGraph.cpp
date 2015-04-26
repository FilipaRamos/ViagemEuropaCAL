#include "DisplayGraph.h"
#include <string>
#include <iostream>
#include <cstdlib>


DisplayGraph::DisplayGraph(){
}

void DisplayGraph::Display(Graph<Cidade> gc) {

	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeColor("BLUE");

	gv->defineVertexColor("BLACK");

	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		while (i < gc.getVertexSet().at(i)->getInfo().getTemposViagem().size()) {
		gv->addNode(gc.getVertexSet().at(i)->getInfo().getTemposViagem().at(i));
		}
	}

	for (size_t i = 1; i <= gc.getVertexSet().size(); ++i) {
		unsigned int j = 0;
		while (j < gc.getVertexSet().at(i)->getInfo().getTemposViagem().size()) {
			gv->addEdge(gc.getVertexSet().at(i)->getInfo().getClassificacao(), gc.getVertexSet().at(i-1)->getInfo().getClassificacao(), gc.getVertexSet().at(i)->getInfo().getTemposViagem()[j], EdgeType::UNDIRECTED);
			gv->addEdge(gc.getVertexSet().at(i)->getInfo().getClassificacao(), gc.getVertexSet().at(i-1)->getInfo().getClassificacao(), gc.getVertexSet().at(i)->getInfo().getTemposViagem()[j], EdgeType::UNDIRECTED);

			++j;
		}
	}

}


