#include "header/header.h"

// constructor
ArrayList::ArrayList() {
	this->data = new Student[50];
	this->amount = 0;
	this->MAX_SIZE = 50;
}

ArrayList::ArrayList(int size) {
	if(size <= 0) {
		cout << "Size must bigger than 0!!" << endl;
		exit(1);
	}

	this->data = new Student[size];
	this->MAX_SIZE = size;
	this->amount = 0;
}

// Release memory
ArrayList::~ArrayList() {
	delete [] this->data;
}

ostream & operator<<(ostream & os, ArrayList & list) { 
	cout << "There are " << list.amount << " elements in this list" << endl;

	os << "Id\tName\tRoomId\t" << endl;
	for(int ix = 0 ; ix < list.amount ; ++ix) {
		os << list.data[ix].getId() << "\t"
			<< list.data[ix].getName() << "\t"
			<< list.data[ix].getRoomId() << "\t"
			<< std::endl;
	}

	return os;
}

// Append single Student object to list
bool ArrayList::append(Student & stu) {
	if(isFull()) {
		cout << "List is full!" << endl;
		return false;
	}

	this->data[this->amount++] = stu;
	
	return true;
}
