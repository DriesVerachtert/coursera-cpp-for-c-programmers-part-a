/*
 * ShortestPathCalculatorTest.cpp
 *
 *  Created on: 11 Jun 2017
 *      Author: Dries Verachtert
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ShortestPathCalculatorTest
#include <boost/test/unit_test.hpp>
#include "ShortestPathCalculator.h"
#include <vector>
#include <stdexcept>

/*
 * Various tests to make sure that the shortest path is calculated correctly.
 * The returned path of vertices isn't tested in detail in the test with
 * the bigger graph => could be improved.
 */
BOOST_AUTO_TEST_SUITE(ShortestPathCalculatorTestSuite)

BOOST_AUTO_TEST_CASE(exc) {
	Graph g(3);
	ShortestPathCalculator c(g);
	BOOST_CHECK_THROW(c.calculateShortestPath(-1,2), std::invalid_argument);
	BOOST_CHECK_THROW(c.calculateShortestPath(0,3), std::invalid_argument);
	BOOST_CHECK_THROW(c.calculateShortestPath(-2,3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(graph2) {
	Graph g(2);
	g.addEdge(0, 1, 1.0);
	ShortestPathCalculator c(g);
	auto result = c.calculateShortestPath(0,1);
	BOOST_CHECK_EQUAL(result.first, 1.0);
	BOOST_CHECK_EQUAL(result.second.size(), 2);
	BOOST_CHECK_EQUAL(result.second.front(), 0);
	BOOST_CHECK_EQUAL(result.second.back(), 1);
	result = c.calculateShortestPath(1,0);
	BOOST_CHECK_EQUAL(result.first, 1.0);
	BOOST_CHECK_EQUAL(result.second.size(), 2);
	BOOST_CHECK_EQUAL(result.second.front(), 1);
	BOOST_CHECK_EQUAL(result.second.back(), 0);
}
BOOST_AUTO_TEST_CASE(graph3_0) {
	Graph g(3);
	g.addEdge(0, 2, 3.0);

	ShortestPathCalculator c(g);
	BOOST_CHECK_THROW(c.calculateShortestPath(0,1), std::domain_error);
	BOOST_CHECK_THROW(c.calculateShortestPath(1,0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(graph3_1) {
	Graph g(3);
	g.addEdge(0, 2, 3.0);
	g.addEdge(2, 1, 4.0);

	ShortestPathCalculator c(g);
	auto result = c.calculateShortestPath(0,2);
	BOOST_CHECK_EQUAL(result.first, 3.0);
	BOOST_CHECK_EQUAL(result.second.size(), 2);
	BOOST_CHECK_EQUAL(result.second.front(), 0);
	BOOST_CHECK_EQUAL(result.second.back(), 2);

	result = c.calculateShortestPath(1,2);
	BOOST_CHECK_EQUAL(result.first, 4.0);
	BOOST_CHECK_EQUAL(result.second.size(), 2);
	BOOST_CHECK_EQUAL(result.second.front(), 1);
	BOOST_CHECK_EQUAL(result.second.back(), 2);
}
BOOST_AUTO_TEST_CASE(graph3_2) {
	Graph g(3);
	g.addEdge(0, 2, 3.0);
	g.addEdge(2, 1, 4.0);

	ShortestPathCalculator c(g);
	auto result = c.calculateShortestPath(0,1);
	BOOST_CHECK_EQUAL(result.first, 7.0);
	BOOST_CHECK_EQUAL(result.second.size(), 3);
	BOOST_CHECK_EQUAL(result.second.front(), 0);
	BOOST_CHECK_EQUAL(result.second.back(), 1);
	result = c.calculateShortestPath(1,0);
	BOOST_CHECK_EQUAL(result.first, 7.0);
	BOOST_CHECK_EQUAL(result.second.size(), 3);
	BOOST_CHECK_EQUAL(result.second.front(), 1);
	BOOST_CHECK_EQUAL(result.second.back(), 0);
}

BOOST_AUTO_TEST_CASE(graph_large) {
	Graph g(8);
	g.addEdge(0,1,2.0);
	g.addEdge(0,3,8.0);
	g.addEdge(1,3,2.0);
	g.addEdge(3,2,3.0);
	g.addEdge(3,4,6.0);
	g.addEdge(4,6,1.0);
	g.addEdge(2,6,3.0);
	g.addEdge(6,7,5.0);

	ShortestPathCalculator c(g);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,1).first, 2.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,2).first, 7.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,3).first, 4.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,4).first, 10.0);
	BOOST_CHECK_THROW(c.calculateShortestPath(0,5).first, std::domain_error);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,6).first, 10.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(0,7).first, 15.0);

	BOOST_CHECK_EQUAL(c.calculateShortestPath(1,0).first, 2.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(2,0).first, 7.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(3,0).first, 4.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(4,0).first, 10.0);
	BOOST_CHECK_THROW(c.calculateShortestPath(5,0).first, std::domain_error);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(6,0).first, 10.0);
	BOOST_CHECK_EQUAL(c.calculateShortestPath(7,0).first, 15.0);
}

BOOST_AUTO_TEST_SUITE_END()
