/*
 * PriorityQueue.cpp
 *
 *  Created on: 12 Jun 2017
 *      Author: Dries Verachtert
 */

#include "PriorityQueue.h"
#include <limits>
#include <stdexcept>

/*
 * Insert a new key or update an existing key with a certain priority.
 */
void PriorityQueue::insertOrUpdate(const int key, const float priority) {
	this->_entries[key] = priority;
}

/*
 * Remove a key
 */
void PriorityQueue::remove(const int key) {
	this->_entries.erase(key);
}

/*
 * Get the priority of a key. The key should exist.
 */
float PriorityQueue::getPriority(const int key) const {
	return this->_entries.at(key);
}

/*
 * Return the key with the minimal priority.
 * Note that you'll get an exception if the queue is empty.
 */
int PriorityQueue::getKeyWithMinPriority() const {
	if (this->_entries.size() <= 0) throw std::invalid_argument("can't return key with min priority for empty priority queue");
	int key = -1;
	float prio = std::numeric_limits<float>::max();
	for (auto iter = this->_entries.begin(); iter != this->_entries.end(); ++iter) {
		if (iter->second <= prio) {
			key = iter->first;
			prio = iter->second;
		}
	}
	return key;
}

/*
 * Get the size of the queue.
 */
int PriorityQueue::getSize() const {
	return this->_entries.size();
}

/*
 * Check if a key is contained in the queue.
 */
bool PriorityQueue::containsKey(const int key) const {
	return (!(this->_entries.find(key) == this->_entries.end()));
}
