/*
 * PriorityQueue.h
 *
 *  Created on: 12 Jun 2017
 *      Author: dries
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include <map>

class PriorityQueue {
public:
	PriorityQueue();
	virtual ~PriorityQueue();
	void insertOrUpdate(const int key, const float priority);
	void remove(const int key);
	float getPriority(const int key) const;
	//void updatePriority(const int key, const float newPriority);
	int getKeyWithMinPriority() const;
	int getSize() const;
	bool containsKey(const int key) const;
private:
	std::map<int,float> entries;
};

#endif /* PRIORITYQUEUE_H_ */
