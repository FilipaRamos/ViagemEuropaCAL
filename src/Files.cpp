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
 * 1ª linha --> tempo disponível (em dias)
 * 2ª linha --> número de cidades a visitar
 * ... --> nome da cidade
 * ... --> classificação (vontade de visitar)
 * ... --> tempo que quer passar na cidade
 * ... --> tempo que demora a viajar
 * ... --> para as cidades imediatamente a baixo
 *
 * ... --> nome da 2ª cidade
 * (...)
 */

/*
 * Função para ler os ficheiros com a informação necessária ao cálculo do melhor caminho
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
		file >> tempo_disponivel; // guardar o tempo disponível numa variável geral
		file >> n_cidades; // guardar o número de cidades
		for(int i = 0; i < n_cidades; ++i){ // ler a informação sobre as cidades
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



