#include "DisplayGraph.h"
#include <string>
#include <iostream>
#include <cstdlib>


DisplayGraph::DisplayGraph(){
}

int DisplayGraph::StringInt(string st) {

	const char *str1 = st.c_str();

	return atoi(str1);

}

void DisplayGraph::Display(Graph<Cidade> gc) {

	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeColor("BLUE");

	gv->defineVertexColor("BLACK");

	//ADICIONA OS NOS TODOS
	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		gv->addNode(i);
	}

//TENTA ADICIONAR O EDGE
	int id = 0;
	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		unsigned int j = 0;
		int no = i+1;
		while (j < (gc.getVertexSet().size() - (i + 1))) {
			gv->addEdge(id, i, no, EdgeType::UNDIRECTED);
			j++;
			id++;
			no++;
		}
	}

}


