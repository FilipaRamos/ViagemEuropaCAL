#include "DisplayGraph.h"
#include <string>
#include <iostream>
#include <cstdlib>

DisplayGraph::DisplayGraph() {
}


void DisplayGraph::Display(Graph<Cidade> gc, vector<Cidade> cidadesAusar,bool setColorEdge) {

	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeColor("BLUE");

	gv->defineVertexColor("BLACK");

	int x = 10, y = 10;


	//ADICIONA OS NOS TODOS
	for (unsigned int i = 0; i < gc.getVertexSet().size(); ++i, ++x, ++y) {
		gv->addNode(i, x, y);
		for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
			gv->addNode(i);
			gv->setVertexLabel(i, gc.getVertexSet().at(i)->getInfo().getNome());
			if(gc.getVertexSet().at(i)->getInfo().getClassificacao() == 10)
					gv->setVertexColor(i,"YELLOW");
		}

		//TENTA ADICIONAR O EDGE
		int id = 0;
		for (size_t i = 0; i < gc.getVertexSet().size(); ++i) {
			unsigned int j = 0;
			int no = i + 1;
			while (j < (gc.getVertexSet().size() - (i + 1))) {
				gv->addEdge(id, i, no, EdgeType::UNDIRECTED);
				int number =
						gc.getVertexSet().at(i)->getInfo().getTemposViagem().at(
								j);
				ostringstream ss;
				ss << number;
				gv->setEdgeLabel(id, ss.str());
				if(find(cidadesAusar.begin(), cidadesAusar.end(), gc.getVertexSet().at(i)->getInfo()) != cidadesAusar.end() && !setColorEdge)
					gv->setEdgeColor(i,"GREEN");
				j++;
				id++;
				no++;
			}
		}
	}
}


