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
	this->numOfVertices = numberOfVertices;
	this->edges = new float*[numberOfVertices];
	for (int i=0;i<numberOfVertices;i++) {
		this->edges[i] = new float[numberOfVertices];
		for (int j=0;j<numberOfVertices;j++) {
			this->edges[i][j] = -1;
		}
	}
	this->numOfEdges = 0;
}

Graph::~Graph() {
	delete this->edges;
}

int Graph::getNumberOfVertices() const {
	return this->numOfVertices;
}
int Graph::getNumberOfEdges() const {
	return this->numOfEdges;
}
bool Graph::isAdjacent(const int vertex1, const int vertex2) const {
	if (vertex1 < 0 || vertex1 >= numOfVertices || vertex2 < 0 || vertex2 >= numOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (this->edges[vertex1][vertex2] == -1) {
		return false;
	} else {
		return true;
	}
}
std::vector<int> Graph::getNeighbors(const int vertex) const {
	if (vertex < 0 || vertex >= numOfVertices) throw std::invalid_argument("vertex has an invalid value");

	std::vector<int> retval;
	for (int i=0;i<numOfVertices;i++) {
		if (this->edges[vertex][i] >= 0) {
			retval.push_back(i);
		}
	}
	return retval;
}

void Graph::addEdge(const int vertex1, const int vertex2, const float distance) {
	if (vertex1 < 0 || vertex1 >= numOfVertices || vertex2 < 0 || vertex2 >= numOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (distance < 0) throw std::exception();
	this->numOfEdges++;
	this->edges[vertex1][vertex2] = distance;
	this->edges[vertex2][vertex1] = distance;
}

float Graph::getDistanceOfEdge(const int vertex1, const int vertex2) const {
	if (vertex1 < 0 || vertex1 >= numOfVertices || vertex2 < 0 || vertex2 >= numOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (this->edges[vertex1][vertex2] == -1) {
		throw std::invalid_argument("no edge between those vertices");
	} else {
		return this->edges[vertex1][vertex2];
	}
}
