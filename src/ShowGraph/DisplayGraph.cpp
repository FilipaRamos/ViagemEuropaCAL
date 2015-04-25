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

	//ADICIONA OS NOS TODOS

	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		gv->addNode(gc.getVertexSet().at(i)->getInfo().getTemposViagem().at(i));

	}
	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		for (size_t j = 0; j < gc.getVertexSet().at(i)->getAdj().size(); ++j) {
			gv->addEdge(gc.getVertexSet().at(i)->getInfo().getClassificacao(), gc.getVertexSet().at(i+1)->getInfo().getClassificacao(), gc.getVertexSet().at(i)->getInfo().getTemposViagem()[j], EdgeType::UNDIRECTED);
			gv->addEdge(gc.getVertexSet().at(i)->getInfo().getClassificacao(), gc.getVertexSet().at(i+1)->getInfo().getClassificacao(), gc.getVertexSet().at(i)->getInfo().getTemposViagem()[j+1], EdgeType::UNDIRECTED);
		}
	}

}


