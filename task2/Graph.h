/*
 * Graph.h
 *
 *  Created on: 8 Jun 2017
 *      Author: Dries Verachtert
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

/*
 * Represent a graph with a fixed number of vertices and a variable number of edges.
 * There can only be 0 or 1 edges between two vertices. Edges have no direction.
 * Each edge has a positive distance represented as a float.
 */
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
	int _numberOfVertices;
	int _numberOfEdges;
};

#endif /* GRAPH_H_ */
