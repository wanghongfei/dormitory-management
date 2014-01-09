#ifndef UTILITY_H_H
#define UTILITY_H_H

#include "header.h"
using namespace std;

class Utility {
	public:
		int exec();

	private:
		void showMenu();
		void pause();
		void readDataFromFile(const string & fileName, ArrayList & list);

		void queryById();
		void queryByName();
		void queryByRoomId();

	private:
		//ArrayList list(100); // ERROR
		ArrayList list;
};

#endif

