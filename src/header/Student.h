#ifndef STUDENT_H_H
#define STUDENT_H_H

#include "header.h"
using namespace std;

// Entity class
class Student {
	public:
		// constructor
		Student(const string & name, const string & id, const string & roomId) : name(name), id(id), roomId(roomId) {}
		Student() {}

		// getters and setters
		string getName() {
			return this->name;
		}
		
		void setName(const string & name) {
			this->name = name;
		}
		
		string getId() {
			return this->id;
		}

		void setId(const string & id) {
			this->id = id;
		}

		string getRoomId() {
			return this->roomId;
		}

		void setRoomId(const string & roomId) {
			this->roomId = roomId;
		}
		
	private:
		string name;
		string id;
		string roomId;
};

//ostream & operator<<(ostream & os, Student & stu) {
//	os << "\t" << stu.getId()
//		<< "\t" << stu.getName()
//		<< "\t" << stu.getRoomId()
//		<< endl;
//
//	return os;
//}


#endif
