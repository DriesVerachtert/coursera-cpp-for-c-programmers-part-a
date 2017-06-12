/*
 * PriorityQueueTest.cpp
 *
 *  Created on: 12 Jun 2017
 *      Author: dries
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PriorityQueueTest
#include <boost/test/unit_test.hpp>
#include "PriorityQueue.h"
#include <vector>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(PriorityQueueTestSuite)

BOOST_AUTO_TEST_CASE(test1) {
	PriorityQueue p;
	BOOST_CHECK_EQUAL(p.getSize(), 0);
	BOOST_CHECK(!p.containsKey(5));

	p.insertOrUpdate(5, 3.3);
	BOOST_CHECK_EQUAL(p.getSize(), 1);
	BOOST_CHECK(p.containsKey(5));
	BOOST_CHECK(!p.containsKey(3));
	BOOST_CHECK_EQUAL(p.getKeyWithMinPriority(), 5);
	BOOST_CHECK_CLOSE(p.getPriority(5), 3.3, 0.001);

	p.insertOrUpdate(3, 2.7);
	BOOST_CHECK_EQUAL(p.getSize(), 2);
	BOOST_CHECK(p.containsKey(5));
	BOOST_CHECK(p.containsKey(3));
	BOOST_CHECK(!p.containsKey(2));
	BOOST_CHECK_EQUAL(p.getKeyWithMinPriority(), 3);
	BOOST_CHECK_CLOSE(p.getPriority(5), 3.3, 0.001);
	BOOST_CHECK_CLOSE(p.getPriority(3), 2.7, 0.001);

	p.insertOrUpdate(5, 1.4);
	BOOST_CHECK_EQUAL(p.getSize(), 2);
	BOOST_CHECK(p.containsKey(5));
	BOOST_CHECK(p.containsKey(3));
	BOOST_CHECK(!p.containsKey(2));
	BOOST_CHECK_EQUAL(p.getKeyWithMinPriority(), 5);
	BOOST_CHECK_CLOSE(p.getPriority(5), 1.4, 0.001);
	BOOST_CHECK_CLOSE(p.getPriority(3), 2.7, 0.001);

	p.remove(5);
	BOOST_CHECK_EQUAL(p.getSize(), 1);
	BOOST_CHECK(!p.containsKey(5));
	BOOST_CHECK(p.containsKey(3));
	BOOST_CHECK_EQUAL(p.getKeyWithMinPriority(), 3);
	BOOST_CHECK_CLOSE(p.getPriority(3), 2.7, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()
