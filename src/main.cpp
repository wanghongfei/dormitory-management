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

Utility util;

int main() {
	ArrayList list(50);

	//list.append(st);
	//list.append(st2);

	//cout << list << endl;

	util.readDataFromFile("data.dat", list);
	list.quickSort(0, list.getAmount() - 1, ID);
	cout << list << endl;

	cout << list.queryById("00") << endl;;
	cout << list.queryByName("Neo") << endl;

	return 0;
}
