/*
 * RandomGraphGenerator.h
 *
 *  Created on: 10 Jun 2017
 *      Author: Dries Verachtert
 */

#ifndef RANDOMGRAPHGENERATOR_H_
#define RANDOMGRAPHGENERATOR_H_
#include "Graph.h"

/*
 * Can generate random graphs with a given number of vertices, edge density and distance range.
 * Note that srand must be initialised before you use this class.
 */
class RandomGraphGenerator {
public:
//	RandomGraphGenerator();
//	virtual ~RandomGraphGenerator();

	Graph generateGraph(int numberOfVertices, float edgeDensity, float minDistance, float maxDistance);
private:
	float getRandomFloatZeroToOne();
	float getRandomFloat(float minValue, float maxValue);
};

#endif /* RANDOMGRAPHGENERATOR_H_ */
