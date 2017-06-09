/*
 * GraphTest.cpp
 *
 *  Created on: 8 Jun 2017
 *      Author: dries
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE GraphTest
#include <boost/test/unit_test.hpp>
#include <Graph.h>

BOOST_AUTO_TEST_SUITE(GraphTestSuite)

BOOST_AUTO_TEST_CASE(ctr0)
{
	Graph g = Graph(0);
	BOOST_CHECK_EQUAL(g.getNumberOfEdges(), 0);
	BOOST_CHECK_EQUAL(g.getNumberOfVertices(), 0);
}

BOOST_AUTO_TEST_CASE(ctr1)
{
	Graph g = Graph(1);
	BOOST_CHECK_EQUAL(g.getNumberOfEdges(), 0);
	BOOST_CHECK_EQUAL(g.getNumberOfVertices(), 1);
}

BOOST_AUTO_TEST_CASE(ctr_neg)
{
	BOOST_CHECK_THROW(Graph(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ctr10)
{
	Graph g = Graph(10);
	BOOST_CHECK_EQUAL(g.getNumberOfEdges(), 0);
	BOOST_CHECK_EQUAL(g.getNumberOfVertices(), 10);
	BOOST_CHECK_EQUAL(g.isAdjacent(0, 1), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(1, 0), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(5, 3), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(6, 2), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(9, 9), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(6, 3), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(4, 2), false);
	BOOST_CHECK_EQUAL(g.getNeighbors(0).empty(), true);
	BOOST_CHECK_EQUAL(g.getNeighbors(9).empty(), true);
	BOOST_CHECK_EQUAL(g.getNeighbors(3).empty(), true);
	BOOST_CHECK_EQUAL(g.getNeighbors(6).empty(), true);
	BOOST_CHECK_THROW(g.isAdjacent(-1, 2), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(3, -3), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(-1, -1), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(-1, 12), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(3, 10), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(10, 6), std::invalid_argument);
	BOOST_CHECK_THROW(g.isAdjacent(11, 17), std::invalid_argument);
	BOOST_CHECK_THROW(g.getNeighbors(-1), std::invalid_argument);
	BOOST_CHECK_THROW(g.getNeighbors(10), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(edge1)
{
	Graph g = Graph(3);
	g.addEdge(0,1,5);
	BOOST_CHECK_EQUAL(g.getNumberOfEdges(), 1);
	BOOST_CHECK_EQUAL(g.isAdjacent(0, 1), true);
	BOOST_CHECK_EQUAL(g.isAdjacent(1, 0), true);
	BOOST_CHECK_EQUAL(g.isAdjacent(2, 1), false);
	BOOST_CHECK_EQUAL(g.isAdjacent(0, 2), false);
	BOOST_CHECK_EQUAL(g.getNeighbors(0).empty(), false);
	BOOST_CHECK_EQUAL(g.getNeighbors(1).empty(), false);
	BOOST_CHECK_EQUAL(g.getNeighbors(0).size(), 1);
	BOOST_CHECK_EQUAL(g.getNeighbors(1).size(), 1);
	BOOST_CHECK_EQUAL(g.getNeighbors(0).at(0), 1);
	BOOST_CHECK_EQUAL(g.getNeighbors(1).at(0), 0);

	BOOST_CHECK_EQUAL(g.getNeighbors(2).empty(), true);
}

BOOST_AUTO_TEST_SUITE_END()
