/*
 * Graph.h
 *
 *  Created on: 8 Jun 2017
 *      Author: dries
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>


class Graph {
public:
	Graph(const int numberOfVertices);
	virtual ~Graph();

	int getNumberOfVertices() const;
	int getNumberOfEdges() const;
	bool isAdjacent(const int vertex1, const int vertex2) const;
	std::vector<int> getNeighbors(const int vertex) const;
	void addEdge(const int vertex1, const int vertex2, const float distance);
	float getDistanceOfEdge(const int vertex1, const int vertex2) const;
private:
	float** edges = nullptr;
	int numOfVertices;
	int numOfEdges;
};

#endif /* GRAPH_H_ */
