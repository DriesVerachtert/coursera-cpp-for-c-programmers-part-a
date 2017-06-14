/*
 * RandomGraphGenerator.cpp
 *
 *  Created on: 10 Jun 2017
 *      Author: Dries Verachtert
 */

#include "RandomGraphGenerator.h"
#include <stdexcept>
#include <cstdlib>

/*
 * Generate 1 random graph according to the given number of vertices, edge density and distance range.
 */
Graph RandomGraphGenerator::generateGraph(int numberOfVertices, float edgeDensity, float minDistance, float maxDistance) {
	if (numberOfVertices < 0) throw std::invalid_argument("numberOfVertices should be >= 0");
	if (edgeDensity < 0) throw std::invalid_argument("edgeDensity should be >= 0");
	if (minDistance < 0) throw std::invalid_argument("minDistance should be >= 0");
	if (maxDistance < 0) throw std::invalid_argument("maxDistance should be >= 0");
	if (minDistance > maxDistance) throw std::invalid_argument("minDistance should be smaller or equal to maxDistance");

	Graph g(numberOfVertices);
	for (int i=0;i<numberOfVertices; i++) {
		for (int j=0;j<numberOfVertices;j++) {
			if (getRandomFloatZeroToOne() < edgeDensity) {
				g.addEdge(i, j, getRandomFloat(minDistance, maxDistance));
			}
		}
	}
	return g;
}

/*
 * Get 1 random float in the range 0 to 1.
 */
float RandomGraphGenerator::getRandomFloatZeroToOne() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

/*
 * Get 1 random float in the given range.
 */
float RandomGraphGenerator::getRandomFloat(float minValue, float maxValue) {
	return minValue + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxValue-minValue)));
}

