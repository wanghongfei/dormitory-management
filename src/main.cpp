#include "header/header.h"

using namespace std;

/*
 * School Assignment: A dormitory management program
 *
 * Author: wanghongfei
 * Creating time: 1/8/2014
 * Last modify: 1/8/2014
 * Language: C++
 */

ostream & operator<<(ostream & os, Student & stu) {
	os << "Id\tName\tRoomId\t" << endl;
	os << stu.getId() << "\t"
		<< stu.getName() << "\t"
		<< stu.getRoomId() << "\t"
		<< endl;

	return os;
}

int main() {
	Utility util;
	ArrayList list(50);

	Student st("bruce", "001", "129");
	Student st2("Neo", "001", "128");

	list.append(st);
	list.append(st2);

	cout << list << endl;

	return 0;
}
