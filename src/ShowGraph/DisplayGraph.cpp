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
			gv->addNode(gc.getVertexSet().at(i)->getInfo().getClassificacao());
	}

//TENTA ADICIONAR O EDGE

	for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
		unsigned int j = 0;
		int no = i+1;
		while (j < (gc.getVertexSet().size() - (i + 1))) {
			cout << "i: " << i << endl;
			cout << "no inicial " << no << endl;
			gv->addEdge(gc.getVertexSet().at(i)->getInfo().getTemposViagem()[j],
					gc.getVertexSet().at(i)->getInfo().getClassificacao(),
					gc.getVertexSet().at(no)->getInfo().getClassificacao(),
					EdgeType::UNDIRECTED);
			j++;
			no++;
			cout << "j: " << j << endl;
		}
	}

}


