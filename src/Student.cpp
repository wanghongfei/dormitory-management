#include "header/header.h"

ostream & operator<<(ostream & os, Student & stu) {
	os << "\t" << stu.getId()
		<< "\t" << stu.getName()
		<< "\t" << stu.getRoomId()
		<< endl;

	return os;
}
