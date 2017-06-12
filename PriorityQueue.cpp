/*
 * PriorityQueue.cpp
 *
 *  Created on: 12 Jun 2017
 *      Author: dries
 */

#include "PriorityQueue.h"
#include <limits>
#include <stdexcept>

PriorityQueue::PriorityQueue() {
}

PriorityQueue::~PriorityQueue() {
}

void PriorityQueue::insertOrUpdate(const int key, const float priority) {
	this->entries[key] = priority;
}

void PriorityQueue::remove(const int key) {
	this->entries.erase(key);
}

float PriorityQueue::getPriority(const int key) const {
	return this->entries.at(key);
}

int PriorityQueue::getKeyWithMinPriority() const {
	if (this->entries.size() <= 0) throw std::invalid_argument("can't return key with min priority for empty priority queue");
	int key = -1;
	float prio = std::numeric_limits<float>::max();
	for (auto iter = this->entries.begin(); iter != this->entries.end(); ++iter) {
		if (iter->second <= prio) {
			key = iter->first;
			prio = iter->second;
		}
	}
	return key;
}

int PriorityQueue::getSize() const {
	return this->entries.size();
}

bool PriorityQueue::containsKey(const int key) const {
	return (!(this->entries.find(key) == this->entries.end()));
}
