/*
 * ShortestPathCalculator.cpp
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#include "ShortestPathCalculator.h"
#include <stdexcept>
#include <vector>
#include <map>
#include <limits>
#include "PriorityQueue.h"


ShortestPathCalculator::~ShortestPathCalculator() {
}

std::pair<float,std::vector<int>>  ShortestPathCalculator::calculateShortestPath(const int startVertex, const int endVertex) {
	if (startVertex < 0 || startVertex >= _graph.getNumberOfVertices() || endVertex < 0 || endVertex >= _graph.getNumberOfVertices()) throw std::invalid_argument("startVertex or endVertex not valid");

	PriorityQueue pq;
	std::map<int,int> vertexToPrevious;

	for (int i=0;i<_graph.getNumberOfVertices(); i++) {
		pq.insertOrUpdate(i, std::numeric_limits<float>::max());
		vertexToPrevious[i] = -1;
	}
	pq.insertOrUpdate(startVertex, 0.0);

	while (pq.getSize() > 0) {
		int closestVertex = pq.getKeyWithMinPriority();
		float distanceToClosestVertex = pq.getPriority(closestVertex);
		if (distanceToClosestVertex == std::numeric_limits<float>::max()) {
			throw std::domain_error("no path between those vertices");
		}
		if (closestVertex == endVertex) {
			std::vector<int> path;
			int someVertex = closestVertex;
			while (someVertex != startVertex) {
				path.insert(path.begin(), someVertex);
				someVertex = vertexToPrevious[someVertex];
			}
			path.insert(path.begin(), startVertex);
			std::pair<float,std::vector<int>> retval;
			retval.first = distanceToClosestVertex;
			retval.second = path;
			return retval;
		}
		pq.remove(closestVertex);

		std::vector<int> neighbours = _graph.getNeighbors(closestVertex);
		for (auto const& neighbourVertex: neighbours) {
			float calculatedDistance = distanceToClosestVertex + _graph.getDistanceOfEdge(closestVertex, neighbourVertex);
			if (pq.containsKey(neighbourVertex) && calculatedDistance < pq.getPriority(neighbourVertex)) {
				pq.insertOrUpdate(neighbourVertex, calculatedDistance);
				vertexToPrevious[neighbourVertex] = closestVertex;
			}

		}
	}

	throw std::domain_error("could not calculate path");
}
