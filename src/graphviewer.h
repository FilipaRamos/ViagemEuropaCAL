#ifndef _GRAPH_VIEWER_H_
#define _GRAPH_VIEWER_H_
<<<<<<< HEAD

=======
/*
>>>>>>> origin/master
#ifdef linux
	#include <unistd.h>
#else
	#include <winsock2.h>
	#include <Windows.h>
#endif

#include <stdlib.h>
#include <signal.h>
#include <string>

#include "edgetype.h"
#include "connection.h"

#define BLUE "BLUE"
#define RED "RED"
#define PINK "PINK"
#define BLACK "BLACK"
#define WHITE "WHITE"
#define ORANGE "ORANGE"
#define YELLOW "YELLOW"
#define GREEN "GREEN"
#define CYAN "CYAN"
#define GRAY "GRAY"
#define DARK_GRAY "DARK_GRAY"
#define LIGHT_GRAY "LIGHT_GRAY"
#define MAGENTA "MAGENTA"

/**
 * Classe que guarda o grafo e o representa. Todas as suas funções retornam um booleano a indicar
 * se a sua execução decorreu ou não com sucesso.
 */
<<<<<<< HEAD
class GraphViewer {
 public:
  /**
   * Variável que guarda a próxima porta que o programa vai usar. O valor inicial é 7772.
   */
  static short port;
=======
//class GraphViewer {
 //public:
  /**
   * Variável que guarda a próxima porta que o programa vai usar. O valor inicial é 7772.
   */
  //static short port;
>>>>>>> origin/master
  
  /**
   * Construtor que cria um novo grafo e atribui automaticamente a porta.
   * @param width Inteiro que representa a lagura da área do grafo.
   * @param height Inteiro que representa a altura da área do grafo.
   * @param dynamic Booleano que determina se a localização dos nós é automaticamente.
   * determinado pelo programa (true) ou se deve ser determinado pelo utilizador (false).
   */
<<<<<<< HEAD
  GraphViewer(int width, int height, bool port_n);
=======
  //GraphViewer(int width, int height, bool port_n);
>>>>>>> origin/master
  
  /**
   * Construtor que cria um novo grafo, utilizando uma porta especificada pelo utilizador para a ligação.
   * @param width Inteiro que representa a lagura da área do grafo.
   * @param height Inteiro que representa a altura da área do grafo.
   * @param dynamic Booleano que determina se a localização dos nós é automaticamente.
   * determinado pelo programa (true) ou se deve ser determinado pelo utilizador (false).
   * @param port_n Inteiro que determina a porta a utilizar. Deve-se ter cuidado para não utilizar uma porta
   * já usada por outro programa ou pelo sistema.
   */
<<<<<<< HEAD
  GraphViewer(int width, int height, bool dynamic, int port_n);
=======
  //GraphViewer(int width, int height, bool dynamic, int port_n);
>>>>>>> origin/master
  
  /**
   * Função que cria a janela para visualização.
   * @param width Largura da janela a criar.
   * @param height Altura da janela a criar.
   */
<<<<<<< HEAD
  bool createWindow(int width, int height);
  /**
   * Fecha a janela a ser utilizada para visualização.
   */
  bool closeWindow();
=======
  //bool createWindow(int width, int height);
  /**
   * Fecha a janela a ser utilizada para visualização.
   */
  //bool closeWindow();
>>>>>>> origin/master

  /**
   * Acrescenta um nó à representação do grafo, numa posição específica, irrelevante se o grafo
   * for dinâmico.
   * @param id Identificador único do nó.
   * @param x Posição horizontal do nó.
   * @param y Posição vertical do nó.
   */
<<<<<<< HEAD
  bool addNode(int id, int x, int y);
=======
  //bool addNode(int id, int x, int y);
>>>>>>> origin/master
  /**
   * Acrescenta um nó à representação do grafo, numa posição ao critério do programa.
   * @param id Identificador único do nó.
   */
<<<<<<< HEAD
  bool addNode(int id); 
=======
  //bool addNode(int id);
>>>>>>> origin/master
  /**
   * Acrescenta uma aresta à representação do grafo.
   * @param id Identificador único da aresta.
   * @param v1 Identificador único do nó de origem da aresta.
   * @param v2 Identificador único do nó de destino da aresta.
   * @param edgeType EdgeType.DIRECTED caso a aresta seja unidirecional
   * ou EdgeType.UNDIRECTED caso a aresta seja bidirecional.
   */
<<<<<<< HEAD
  bool addEdge(int id, int v1, int v2, int edgeType);
=======
  //bool addEdge(int id, int v1, int v2, int edgeType);
>>>>>>> origin/master

  /**
   * Remove um nó da representação do grafo e todas as arestas ligadas a este.
   * @param id Identificador único do nó a a remover.
   */
<<<<<<< HEAD
  bool removeNode(int id);
=======
  //bool removeNode(int id);
>>>>>>> origin/master
  /**
   * Remove uma aresta da representação do grafo.
   * @param id Identificador único da aresta a remover.
   */
<<<<<<< HEAD
  bool removeEdge(int id); 
=======
  //bool removeEdge(int id);
>>>>>>> origin/master

  /**
   * Função que define o texto de um nó.
   * @param id Identificador único do nó com o texto a alterar.
   * @param label Novo texto do nó.
   */
<<<<<<< HEAD
  bool setVertexLabel(int id, string label);
=======
  //bool setVertexLabel(int id, string label);
>>>>>>> origin/master

  /**
   * Função que define o texto de uma aresta.
   * @param id Identificador único da aresta com o texto a alterar.
   * @param label Novo texto da aresta.
   */
<<<<<<< HEAD
  bool setEdgeLabel(int id, string label);
=======
  //bool setEdgeLabel(int id, string label);
>>>>>>> origin/master
  /**
   * Função que define a cor de uma aresta.
   * @param id Identificador único da aresta com a cor a alterar.
   * @param color Nova cor da aresta, utilizar as constantes definidas no graphviewer.h para conveniência.
   */
<<<<<<< HEAD
  bool setEdgeColor(int id, string color);
=======
  //bool setEdgeColor(int id, string color);
>>>>>>> origin/master

  /**
   * Função que define a cor de um nó.
   * @param id Identificador único do nó com a cor a alterar.
   * @param color Nova cor do nó, utilizar as constantes definidas no graphviewer.h para conveniência.
   */
<<<<<<< HEAD
  bool setVertexColor(int id, string color);
=======
  //bool setVertexColor(int id, string color);
>>>>>>> origin/master

  /**
   * Função que define a cor global das arestas.
   * @param color Nova cor das arestas, utilizar as constantes definidas no graphviewer.h para conveniência.
   */
<<<<<<< HEAD
  bool defineEdgeColor(string color);
=======
  //bool defineEdgeColor(string color);
>>>>>>> origin/master
  /**
   * Função que define a cor global dos nós.
   * @param color Nova cor dos nós, utilizar as constantes definidas no graphviewer.h para conveniência.
   */
<<<<<<< HEAD
  bool defineVertexColor(string color);
=======
  //bool defineVertexColor(string color);
>>>>>>> origin/master
  /**
   * Função que define a espessura de uma aresta.
   * @param id Identificador único da aresta com a espessura a alterar.
   * @param thickness Nova espessura da aresta, sendo que por base, as
   * arestas são criadas com a espessura de 1.
   */
<<<<<<< HEAD
  bool setEdgeThickness(int id, int thickness);
=======
  //bool setEdgeThickness(int id, int thickness);
>>>>>>> origin/master
  
  /**
   * Função que altera a imagem de fundo do grafo.
   * @param path Caminho para o ficheiro com a imagem.
   */
<<<<<<< HEAD
  bool setBackground(string path);
=======
  //bool setBackground(string path);
>>>>>>> origin/master

  /**
   * Função que define o peso de uma aresta na representação do grafo, a ser visualizado
   * como w: valor_do_peso, seguido de qualquer outro texto associado à aresta.
   * @param id Identificador único da aresta a modificar.
   * @param weight Peso associado à aresta.
   */
<<<<<<< HEAD
  bool setEdgeWeight(int id, int weight);
=======
  //bool setEdgeWeight(int id, int weight);
>>>>>>> origin/master
  /**
   * Função que define o fluxo de uma aresta na representação do grafo, a ser visualizado
   * como f: valor_do_fluxo, precedido pelo peso e seguido por texto definido pelo utilizador.
   * @param id Identificador único da aresta a modificar.
   * @param flow Fluxo associado à aresta.
   */
<<<<<<< HEAD
  bool setEdgeFlow(int id, int flow);
=======
  /*bool setEdgeFlow(int id, int flow);
>>>>>>> origin/master

  /**
   * Função que actualiza a visualização do grafo.
   */
<<<<<<< HEAD
  bool rearrange();

=======
  //bool rearrange();
/*
>>>>>>> origin/master
#ifdef linux
  static pid_t procId;
#endif

 private:
  int width, height;
  bool isDynamic;

  Connection *con;

  void initialize(int, int, bool, int);
};
<<<<<<< HEAD
=======
*/
>>>>>>> origin/master

#endif
