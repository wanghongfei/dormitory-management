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
		bool append(Student & stu);
		friend ostream & operator<<(ostream & os, ArrayList & list); // print all elements to standard output device.

		// query method
		int queryById(const string & id);
		int queryByName(const string & name);
		int queryByRoomId(const string & roomId);

		int getAmount() {
			return this->amount;
		}

		Student* getElements() {
			return this->data;
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

	public:
		// quick sort
		int portion(int ixLow, int ixHigh, Identifier keyword);
		void quickSort(int ixLow, int ixHigh, Identifier keyword);

		int binSearch(int left, int right, const string & identity, Identifier keyword);
		string fetchKeyword(Student & stu, Identifier keyword);
};

#endif
