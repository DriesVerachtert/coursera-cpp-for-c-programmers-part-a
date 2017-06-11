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

BOOST_AUTO_TEST_SUITE_END()
