#ifndef LINKEDLIST_H_H
#define LINKEDLIST_H_H

#include "header.h"

//struct Node {
//	Student data;
//	Node *pNext;
//};

class ArrayList {
	public:
		ArrayList();
		ArrayList(int size);
		virtual ~ArrayList();

		// operation
		Student query(const string & identifier, Identifier type);
		bool append(Student & stu);
		friend ostream & operator<<(ostream & os, ArrayList & list); // print all elements to standard output device.

		int getAmount() {
			return this->amount;
		}

	private:
		Student *data;
		int amount; // node amount
		int MAX_SIZE;

	private:
		bool isFull() {
			return this->amount == this->MAX_SIZE;
		}
		bool isEmpty() {
			return this->amount == 0;
		}
};

#endif
