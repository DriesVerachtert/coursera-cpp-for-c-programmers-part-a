/*
 * ShortestPathCalculator.cpp
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#include "ShortestPathCalculator.h"
#include <stdexcept>

//ShortestPathCalculator::ShortestPathCalculator(const Graph& g) {
//	this->graph = g;
//}

ShortestPathCalculator::~ShortestPathCalculator() {
	// TODO Auto-generated destructor stub
}

void ShortestPathCalculator::calculateShortestPath(const int startVertex, const int endVertex) {
	if (startVertex < 0 || startVertex >= _graph.getNumberOfVertices() || endVertex < 0 || endVertex >= _graph.getNumberOfVertices()) throw std::invalid_argument("startVertex or endVertex not valid");
}
