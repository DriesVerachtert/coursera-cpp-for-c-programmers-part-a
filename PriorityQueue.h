/*
 * PriorityQueue.h
 *
 *  Created on: 12 Jun 2017
 *      Author: Dries Verachtert
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include <map>

/*
 * A priority queue, used as a helper class in the shortest path algorithm.
 * It can contain a bunch of vertices (their numbers), each with a certain priority
 * which is actually a distance value. The method getKeyWithMinPriority returns the
 * key (vertex number) with the lowest priority = lowest distance.
 */
class PriorityQueue {
public:
	void insertOrUpdate(const int key, const float priority);
	void remove(const int key);
	float getPriority(const int key) const;
	int getKeyWithMinPriority() const;
	int getSize() const;
	bool containsKey(const int key) const;
private:
	std::map<int,float> _entries;
};

#endif /* PRIORITYQUEUE_H_ */
