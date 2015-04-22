/*
 * Files.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Filipa
 */
#include <fstream>
#include "Cidade.h"
#include "Files.h"
#include "Viagem.h"

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

File::File(string n){
	file_name = n;
}

int File::readFile(){

	ifstream file;
	file.open(file_name.c_str());
	Viagem v;
	int tempo_disponivel;
	int n_cidades;
	string nm;
	int cls;
	int tmp;
	int distancias;

	if(file.is_open()){
		file >> tempo_disponivel; // guardar o tempo disponível numa variável geral
		file >> n_cidades; // guardar o número de cidades
		file.ignore();
		for(int i = 0; i < n_cidades; ++i){ // ler a informação sobre as cidades
			getline(file, nm);
			file >> cls;
			file >> tmp;
			Cidade cidade (nm, cls, tmp);
			int j = 0;
			while(j < (n_cidades-(i+1))){
				file >> distancias;
				file.ignore();
				cidade.addDistancia(distancias);
				++j;
			}
			v.getCidades().push_back(cidade);
		}
	}

	else{
		cout << "----  Error reading file!  ---- " << endl;
		return 0;
	}

	return tempo_disponivel;

}



