/*
 * Graph.cpp
 *
 *  Created on: 8 Jun 2017
 *      Author: Dries Verachtert
 */

#include "Graph.h"
#include <stdexcept>

/*
 * Represents a graph with a fixed number of vertices: create the array that will contain the edges.
 */
Graph::Graph(const int numberOfVertices) {
	if (numberOfVertices < 0) throw std::invalid_argument("numberOfVertices needs to be >= 0");
	this->_numberOfVertices = numberOfVertices;
	this->edges = new float*[numberOfVertices];
	for (int i=0;i<numberOfVertices;i++) {
		this->edges[i] = new float[numberOfVertices];
		for (int j=0;j<numberOfVertices;j++) {
			this->edges[i][j] = -1;
		}
	}
	this->_numberOfEdges = 0;
}

/*
 * Destructor: delete the array representing the edges.
 */
Graph::~Graph() {
	for (int i=0;i<_numberOfVertices;i++) {
		delete[] this->edges[i];
	}
	delete[] this->edges;
}

/*
 * Get the number of vertices / nodes
 */
int Graph::getNumberOfVertices() const {
	return this->_numberOfVertices;
}

/*
 * Get the number of edges / connections
 */
int Graph::getNumberOfEdges() const {
	return this->_numberOfEdges;
}

/*
 * Is there an edge between two vertices?
 */
bool Graph::isAdjacent(const int vertex1, const int vertex2) const {
	if (vertex1 < 0 || vertex1 >= _numberOfVertices || vertex2 < 0 || vertex2 >= _numberOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (this->edges[vertex1][vertex2] == -1) {
		return false;
	} else {
		return true;
	}
}

/*
 * Get the neighbours of a vertex: all the vertices that have an edge to the given vertex.
 */
std::vector<int> Graph::getNeighbors(const int vertex) const {
	if (vertex < 0 || vertex >= _numberOfVertices) throw std::invalid_argument("vertex has an invalid value");

	std::vector<int> retval;
	for (int i=0;i<_numberOfVertices;i++) {
		if (this->edges[vertex][i] >= 0) {
			retval.push_back(i);
		}
	}
	return retval;
}

/*
 * Add an edge with a given distance. An edge does not have a direction.
 */
void Graph::addEdge(const int vertex1, const int vertex2, const float distance) {
	if (vertex1 < 0 || vertex1 >= _numberOfVertices || vertex2 < 0 || vertex2 >= _numberOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (distance < 0) throw std::exception();
	this->_numberOfEdges++;
	this->edges[vertex1][vertex2] = distance;
	this->edges[vertex2][vertex1] = distance;
}

/*
 * Get the distance of an edge between two vertices.
 */
float Graph::getDistanceOfEdge(const int vertex1, const int vertex2) const {
	if (vertex1 < 0 || vertex1 >= _numberOfVertices || vertex2 < 0 || vertex2 >= _numberOfVertices) throw std::invalid_argument("vertex1 or vertex2 has an invalid value");
	if (this->edges[vertex1][vertex2] == -1) {
		throw std::invalid_argument("no edge between those vertices");
	} else {
		return this->edges[vertex1][vertex2];
	}
}
