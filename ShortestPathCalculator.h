/*
 * ShortestPathCalculator.h
 *
 *  Created on: 10 Jun 2017
 *      Author: Dries Verachtert
 */

#ifndef SHORTESTPATHCALCULATOR_H_
#define SHORTESTPATHCALCULATOR_H_
#include <Graph.h>

/*
 * Calculate shortest paths of a given graph.
 */
class ShortestPathCalculator {
public:
	ShortestPathCalculator(const Graph& graph): _graph(graph) {};
	std::pair<float,std::vector<int>> calculateShortestPath(int startVertex, int endVertex);
private:
	const Graph& _graph;
};

#endif /* SHORTESTPATHCALCULATOR_H_ */
