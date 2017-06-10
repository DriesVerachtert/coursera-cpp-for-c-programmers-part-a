/*
 * RandomGraphGenerator.h
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#ifndef RANDOMGRAPHGENERATOR_H_
#define RANDOMGRAPHGENERATOR_H_
#include "Graph.h"

class RandomGraphGenerator {
public:
	RandomGraphGenerator();
	virtual ~RandomGraphGenerator();

	Graph generateGraph(int numberOfVertices, float edgeDensity, float minDistance, float maxDistance);
private:
	float getRandomFloatZeroToOne();
	float getRandomFloat(float minValue, float maxValue);
};

#endif /* RANDOMGRAPHGENERATOR_H_ */
