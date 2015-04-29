#include "DisplayGraph.h"
#include <string>
#include <iostream>
#include <cstdlib>



DisplayGraph::DisplayGraph() {
}

/*
 * Desenha o grafo inicial construído
 */
void DisplayGraph::DisplayInitialG(Graph<Cidade> gc, vector<Cidade> cidadesAusar,bool setColorEdge) {

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
				j++;
				id++;
				no++;
			}
		}
	}
}

/*
 * Desenha o caminho mais curto com as cidades retornadas do knapsack.cpp
 */
GraphViewer * DisplayGraph::DisplayPath(Graph<Cidade> gc, vector<Cidade> cidadesAusar,bool setColorEdge) {

	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);

	gv->defineEdgeColor("BLUE");

	gv->defineVertexColor("BLACK");

	int x = 10, y = 10;


	//ADICIONA OS NOS TODOS
	for (unsigned int i = 0; i < cidadesAusar.size(); ++i, ++x, ++y) {
		gv->addNode(i, x, y);
		for (size_t i = 0; i < cidadesAusar.size(); ++i) {
			gv->addNode(i);
			gv->setVertexLabel(i, cidadesAusar[i].getNome());
			if(cidadesAusar[i].getClassificacao() == 10)
					gv->setVertexColor(i,"YELLOW");
		}

		//TENTA ADICIONAR O EDGE
		int id = 0;
		unsigned int j = 0;
		for (size_t i = 1; i < cidadesAusar.size(); ++i) {
			gv->addEdge(id, i-1, i, EdgeType::DIRECTED);
			//int number = cidadesAusar[i-1].getTemposViagem().at(j);
			//ostringstream ss;
			//ss << number;
			//gv->setEdgeLabel(id, ss.str());
			j++;
			id++;
		}
		gv->addEdge(id, cidadesAusar.size() - 1, 0, EdgeType::DIRECTED);
		/*cout << id << endl;
		int label = cidadesAusar[0].getTemposViagem().at(cidadesAusar.size()-1);
		ostringstream string;
		string << label;
		gv->setEdgeLabel(id, string.str());*/

	}

	return gv;
}


void DisplayGraph::closeDisplay(GraphViewer gv){
	gv.closeWindow();
}


