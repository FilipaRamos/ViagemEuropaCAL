/*
 * Knapsackproblemtestar.h
 *
 *  Created on: 24/04/2015
 *      Author: Ines
 */

#ifndef SRC_KNAPSACKPROBLEM_H_
#define SRC_KNAPSACKPROBLEM_H_

#include <algorithm>
#include <vector>

#include "Viagem.h"
#include "Cidade.h"
#include "Path.h"
#include "Files.h"



vector<Cidade> Knapsackproblemtestar(int tempoMax);
vector<Cidade> Knapsackproblem(Viagem v, Path p, int tempoMax);
bool FWShortestPath(Path p, vector<Cidade> cidadesAusar, int tempoMax);
void DisplayGraphFW(Path p, vector<Cidade> cidadesAusar);
vector<Cidade> ordenaVector(vector<Cidade> cidadesAusar, Path p);
int tempoNasCidades(vector<Cidade> cidadesAusar);

#endif /* SRC_KNAPSACKPROBLEM_H_ */
