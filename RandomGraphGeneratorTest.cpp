/*
 * RandomGraphGeneratorTest.cpp
 *
 *  Created on: 10 Jun 2017
 *      Author: dries
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RandomGraphGeneratorTest
#include <boost/test/unit_test.hpp>
#include "RandomGraphGenerator.h"
#include <vector>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(RandomGraphGeneratorTestSuite)

BOOST_AUTO_TEST_CASE(gen_density) {
	srand(555);
	RandomGraphGenerator gen;
	for (int i=0;i<10;i++) {
		Graph g = gen.generateGraph(30, 0.3, 0.1, 0.2);
		BOOST_CHECK(g.getNumberOfEdges() > 30*30*0.3*0.9);
		BOOST_CHECK(g.getNumberOfEdges() < 30*30*0.3*1.1);

	}
}

BOOST_AUTO_TEST_CASE(gen_distance) {
	srand(555);
	RandomGraphGenerator gen;
	int numVertices = 20;
	Graph g = gen.generateGraph(numVertices, 0.9, 0.3, 3.2);
	int numAdjacent = 0;
	for (int i=0;i<numVertices;i++) {
		for (int j=0;j<numVertices;j++) {
			if (g.isAdjacent(i,j)) {
				numAdjacent++;
				//std::cout << "checking " << g.getDistanceOfEdge(i,j) << std::endl;
				BOOST_CHECK(g.getDistanceOfEdge(i,j) >= 0.3);
				BOOST_CHECK(g.getDistanceOfEdge(i,j) <= 3.2);
			}
		}
	}
	BOOST_CHECK_EQUAL(numAdjacent, 391);
}


BOOST_AUTO_TEST_CASE(genexc) {
	RandomGraphGenerator gen;
	BOOST_CHECK_THROW(gen.generateGraph(-1, 0.1, 0.1, 0.2), std::invalid_argument);
	BOOST_CHECK_THROW(gen.generateGraph(1, -0.1, 0.1, 0.2), std::invalid_argument);
	BOOST_CHECK_THROW(gen.generateGraph(2, 0.1, -0.1, 0.2), std::invalid_argument);
	BOOST_CHECK_THROW(gen.generateGraph(1, 0.1, 0.1, -0.2), std::invalid_argument);
	BOOST_CHECK_THROW(gen.generateGraph(3, 0.1f, 0.3f, 0.2f), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
