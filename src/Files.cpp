/*
 * Files.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */
#include "Files.h"

/*
 * Formato dos ficheiros a serem lidos
 *
 * 1� linha --> tempo dispon�vel (em dias)
 * 2� linha --> n�mero de cidades a visitar
 * ... --> nome da cidade
 * ... --> classifica��o (vontade de visitar)
 * ... --> tempo que quer passar na cidade
 * ... --> tempo que demora a viajar
 * ... --> para as cidades imediatamente a baixo
 *
 * ... --> nome da 2� cidade
 * (...)
 */

/*
 * Fun��o para ler os ficheiros com a informa��o necess�ria ao c�lculo do melhor caminho
 * --> retorna 0 em caso de falha na leitura do ficheiro
 * --> retorna 1 em caso de sucesso
 */
int File::readFile(){
	ifstream file;
	int n_cidades;
	string nome;
	int classificacao;
	int tempo;
	int distancias;
	if(file.is_open()){
		file >> tempo_disponivel; // guardar o tempo dispon�vel numa vari�vel geral
		file >> n_cidades; // guardar o n�mero de cidades
		for(int i = 0; i < n_cidades; ++i){ // ler a informa��o sobre as cidades
			getline(file, nome);
			file >> classificacao;
			file >> tempo;
			Cidade(nome, classificacao, tempo);


		}
	}
	else{
		cout << "----  Error reading file!  ---- " << endl;
		return 0;
	}

}



