#include "header/header.h"

// constructor
ArrayList::ArrayList() {
	this->data = new Student[50];
	this->amount = 0;
	this->MAX_SIZE = 50;
}

// constructor
ArrayList::ArrayList(int size) {
	if(size <= 0) {
		cout << "Size must bigger than 0!!" << endl;
		exit(1);
	}

	this->data = new Student[size];
	this->MAX_SIZE = size;
	this->amount = 0;
}

// deconstructor
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

// query method
int ArrayList::queryById(const string & id) {
	quickSort(0, this->amount - 1, ID);
	return binSearch(0, this->amount - 1, id, ID);
}
int ArrayList::queryByName(const string & name) {
	quickSort(0, this->amount - 1, NAME);
	return binSearch(0, this->amount - 1, name, NAME);
}
int ArrayList::queryByRoomId(const string & roomId) {
	quickSort(0, this->amount - 1, ROOMID);
	return binSearch(0, this->amount - 1, roomId, ROOMID);
}


// binary search
int ArrayList::binSearch(int left, int right, const string & identity, Identifier keyword) {
	int res = -1; // -1 stands for searching failed.
	while(left <= right) {
		int mid = (left + right) / 2;
		string key = fetchKeyword(this->data[mid], keyword);

		if(identity < key) {
			right = mid - 1;
		} else if(identity > key) {
			left = mid + 1;
		} else {
			res = mid; // Element found
			break;
		}
	}

	return res;
}

// quick sort
int ArrayList::portion(int ixLow, int ixHigh, Identifier keyword) {
	Student initElem = this->data[ixLow];
	string key = fetchKeyword(this->data[ixLow], keyword);

	while(ixLow < ixHigh) {
		while(ixLow < ixHigh && fetchKeyword(this->data[ixHigh], keyword) >= key) {
			--ixHigh;
		}
		this->data[ixLow] = this->data[ixHigh];

		while(ixLow < ixHigh && fetchKeyword(this->data[ixLow], keyword) <= key) {
			++ixLow;
		}
		this->data[ixHigh] = this->data[ixLow];
	}

	this->data[ixLow] = initElem;
	return ixLow;
}

void ArrayList::quickSort(int ixLow, int ixHigh, Identifier keyword) {
	if(ixLow < ixHigh) {
		int ix = portion(ixLow, ixHigh, keyword);
		quickSort(ixLow, ix - 1, keyword);
		quickSort(ix + 1, this->amount - 1, keyword);
	}
}

string ArrayList::fetchKeyword(Student & stu, Identifier keyword) {
	switch(keyword) {
		case ID:
			return stu.getId();

		case ROOMID:
			return stu.getRoomId();

		case NAME:
			return stu.getName();

		default:
			cout << "[ERROR] Cannot happen!" << endl;
			exit(1);
	}
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
