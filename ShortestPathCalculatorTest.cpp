/*
 * ShortestPathCalculatorTest.cpp
 *
 *  Created on: 11 Jun 2017
 *      Author: dries
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ShortestPathCalculatorTest
#include <boost/test/unit_test.hpp>
#include "ShortestPathCalculator.h"
#include <vector>
#include <stdexcept>

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
//	try {
//		c.calculateShortestPath(0,1);
//	} catch (std::exception const &e) {
//		std::cerr << e.what() << std::endl;
//        std::cerr << boost::trace(e);
//	}

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

BOOST_AUTO_TEST_SUITE_END()
