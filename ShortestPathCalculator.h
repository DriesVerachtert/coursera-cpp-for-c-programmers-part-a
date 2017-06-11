/*
 * ShortestPathCalculator.h
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#ifndef SHORTESTPATHCALCULATOR_H_
#define SHORTESTPATHCALCULATOR_H_
#include <Graph.h>

class ShortestPathCalculator {
public:
	ShortestPathCalculator(const Graph& graph): _graph(graph) {};
	virtual ~ShortestPathCalculator();
	void calculateShortestPath(int startVertex, int endVertex);
private:
	const Graph& _graph;
};

#endif /* SHORTESTPATHCALCULATOR_H_ */
