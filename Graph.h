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

	int getNumberOfVertices();
	int getNumberOfEdges();
	bool isAdjacent(const int vertex1, const int vertex2);
	std::vector<int> getNeighbors(const int vertex);
	void addEdge(const int vertex1, const int vertex2, const int distance);
private:
	int** edges = nullptr;
	int numberOfVertices;
	int numberOfEdges;
};

#endif /* GRAPH_H_ */
