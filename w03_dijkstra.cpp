//============================================================================
// Name        : w03_dijkstra.cpp
// Author      : Dries Verachtert
// Version     :
// Copyright   : GPLv3
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "RandomGraphGenerator.h"

int main(void) {
	srand (static_cast <unsigned> (time(0)));
	RandomGraphGenerator g;
	g.generateGraph(3, 0.1f, 0.3f, 0.2f);
}
