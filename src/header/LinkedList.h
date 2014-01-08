#ifndef LINKEDLIST_H_H
#define LINKEDLIST_H_H

#include "header.h"

struct Node {
	Student data;
	Student *pNext;
};

class LinkedList {
	public:
		LinkedList();
		virtual ~LinkedList();

		// operation
		Student query(const string & identifier, Identifier type);
		bool append(Student & stu);

		int getAmount() {
			return this->amount;
		}

	private:
		Node *pFirst; // first node
		Node *pEnd; // last node

		int amount; // node amount
};

#endif
