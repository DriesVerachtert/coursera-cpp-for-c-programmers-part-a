
// Author      : Dries Verachtert
// Copyright   : GPLv3

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "RandomGraphGenerator.h"
#include "ShortestPathCalculator.h"
#include <stdexcept>
#include <iostream>

// Calculate the average distance between all vertices of a random graph (or multiple random graphs) with a given size, density and distance range.
// Not requested, but also support to calculate the average of multiple random graphs instead of just 1.
void calculateAndPrintAverageDistance(int numberOfVertices, float density, float minDistance, float maxDistance, int numberOfRandomGraphs) {
	RandomGraphGenerator gen;

	float totalDistance = 0.0;
	int numberOfShortestPaths = 0;

	for (int i=0;i<numberOfRandomGraphs;i++) {
		Graph graph = gen.generateGraph(numberOfVertices, density, minDistance, maxDistance);
		ShortestPathCalculator calculator = ShortestPathCalculator(graph);
		for (int j=1;j<numberOfVertices;j++) {
			try {
				auto result = calculator.calculateShortestPath(0,j);
				totalDistance = totalDistance + result.first;
				numberOfShortestPaths++;
			} catch (const std::domain_error&) {
				// ignore
			}
		}
	}
	float averageDistance = totalDistance / static_cast<float>(numberOfShortestPaths);
	std::cout << "Average distance for " << numberOfRandomGraphs << " random graph(s) with " << numberOfVertices << " vertices and density " << density << " and distance range " << minDistance << " - " << maxDistance << ": " << averageDistance << std::endl;
}

// The main method: calculate the average distances for graphs of 50 vertices with 2 different densities
int main(void) {
	srand(static_cast<unsigned>(time(0)));

	int numberOfVertices = 50;
	float minDistance = 1.0;
	float maxDistance = 10.0;
	int numberOfRandomGraphs = 1;

	calculateAndPrintAverageDistance(numberOfVertices, 0.2, minDistance, maxDistance, numberOfRandomGraphs);
	calculateAndPrintAverageDistance(numberOfVertices, 0.4, minDistance, maxDistance, numberOfRandomGraphs);

	numberOfRandomGraphs = 1000;
	calculateAndPrintAverageDistance(numberOfVertices, 0.2, minDistance, maxDistance, numberOfRandomGraphs);
	calculateAndPrintAverageDistance(numberOfVertices, 0.4, minDistance, maxDistance, numberOfRandomGraphs);

	return 0;
}
