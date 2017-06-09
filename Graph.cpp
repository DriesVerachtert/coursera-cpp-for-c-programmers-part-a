/*
 * Graph.cpp
 *
 *  Created on: 8 Jun 2017
 *      Author: dries
 */

#include "Graph.h"
#include <stdexcept>

Graph::Graph(const int numberOfVertices) {
	if (numberOfVertices < 0) throw std::invalid_argument("numberOfVertices needs to be >= 0");
	this->numberOfVertices = numberOfVertices;
	this->edges = new int*[numberOfVertices];
	for (int i=0;i<numberOfVertices;i++) {
		this->edges[i] = new int[numberOfVertices];
		for (int j=0;j<numberOfVertices;j++) {
			this->edges[i][j] = -1;
		}
	}
	this->numberOfEdges = 0;
}

Graph::~Graph() {
	delete this->edges;
}

int Graph::getNumberOfVertices() {
	return this->numberOfVertices;
}
int Graph::getNumberOfEdges() {
	return this->numberOfEdges;
}
bool Graph::isAdjacent(const int vertex1, const int vertex2) {
	if (vertex1 < 0 || vertex1 >= numberOfVertices || vertex2 < 0 || vertex2 >= numberOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (this->edges[vertex1][vertex2] == -1) {
		return false;
	} else {
		return true;
	}
}
std::vector<int> Graph::getNeighbors(const int vertex) {
	if (vertex < 0 || vertex >= numberOfVertices) throw std::invalid_argument("vertex has an invalid value");

	std::vector<int> retval;
	for (int i=0;i<numberOfVertices;i++) {
		if (this->edges[vertex][i] >= 0) {
			retval.push_back(i);
		}
	}
	return retval;
}

void Graph::addEdge(const int vertex1, const int vertex2, const int distance) {
	if (vertex1 < 0 || vertex1 >= numberOfVertices || vertex2 < 0 || vertex2 >= numberOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (distance < 0) throw std::exception();
	this->numberOfEdges++;
	this->edges[vertex1][vertex2] = distance;
	this->edges[vertex2][vertex1] = distance;
}
