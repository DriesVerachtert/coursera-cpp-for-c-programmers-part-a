/*
 * RandomGraphGenerator.cpp
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#include "RandomGraphGenerator.h"
#include <stdexcept>
#include <cstdlib>

/**
 * Note that srand must be initialised before you use this class.
 */
RandomGraphGenerator::RandomGraphGenerator() {
	// TODO Auto-generated constructor stub

}

RandomGraphGenerator::~RandomGraphGenerator() {
	// TODO Auto-generated destructor stub
}

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

float RandomGraphGenerator::getRandomFloatZeroToOne() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
float RandomGraphGenerator::getRandomFloat(float minValue, float maxValue) {
	return minValue + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxValue-minValue)));
}

