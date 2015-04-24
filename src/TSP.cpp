#include <iostream>
#include <conio.h>

#include "Viagem.h"

using namespace std;

/*
=======

/*
	Viagem v = new Viagem();

>>>>>>> origin/master
	int i, j, k, n, min, g[20][20], c[20][20], s, s1[20][1], s2, lb;

	n = v.getCidades().size();


	int i, j, k, n, min, g[20][20], c[20][20], s, s1[20][1], s2, lb;


	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			c[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)
				continue;
			else {
				cout << "input" << i << "to" << j << "cost:";
				cin >> c[i][j];
			}
		}
	}
	for (i = 2; i <= n; i++) {
		g[i][0] = c[i][1];
	}
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= n; j++) {
			if (i != j)
				g[i][j] = c[i][j] + g[j][0];
		}
	}
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= n; j++) {
			if (i != j)
				break;
		}
	}
	for (k = 2; k <= n; k++) {

		if (i != k && j != k) {
			if ((c[i][j] + g[i][k]) < (c[i][k] + g[k][j])) {
				g[i][j] = c[i][j] + g[j][k];
				s1[i][j] = j;
			} else {
				g[i][1] = c[i][k] + g[k][j];
				s1[i][1] = k;
			}
		}
	}
	min = c[1][2] + g[2][1];
	s = 2;
	for (i = 3; i < n; i++) {
		if ((c[i][i] + g[i][i]) < min) {
			min = c[1][i] + g[i][1];
			s = i;
		}
	}
	int y = g[i][1] + g[i][j] + g[i][i];
	lb = (y / 2);
	cout << "Edge Matrix";
	for (i = 1; i <= n; i++) {
		cout << "\n";
		for (j = 1; j <= n; j++) {
			cout << "\t" << c[i][j];
		}
	}
	cout << "\n min" << min;
	cout << "\n\b" << lb;
	for (i = 2; i <= n; i++) {
		if (s != i && s1[s][1] != i) {
			s2 = i;
		}
	}
	cout << "\n" << 1 << "-->" << s << "-->" << s1[s][1] << "-->" << s2 << "-->"
			<< 1 << "\n";
	getch();
	return (0);
*/
