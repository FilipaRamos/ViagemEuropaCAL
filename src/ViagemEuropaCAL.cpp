//============================================================================
// Name        : ViagemEuropaCAL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Files.h"
#include "Cidade.h"
#include "Viagem.h"

using namespace std;

int main(){
	int tempo_total;
	File file ("teste.txt");
	tempo_total = file.readFile();
	cout << tempo_total << endl;
	return 0;
}

