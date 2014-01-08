#include "header/header.h"

using namespace std;

void Utility::readDataFromFile(const string & fileName, ArrayList & list) {
	cout << "[INFO] Reading data from file [" << fileName << "]" << endl;

	// open file
	fstream fs;
	fs.open(fileName.c_str());

	if(!fs.is_open()) {
		cout << "[ERROR] File does not exist" << endl;
		return;
	}

	// Read data from file
	// Note: Order matters!
	Student stu;
	string name;
	string id;
	string roomId;
	int tot = 0;
	fs >> tot;
	for(int ix = 0 ; ix < tot ; ++ix) {
		fs >> name >> id >> roomId;

		stu.setName(name);
		stu.setId(id);
		stu.setRoomId(roomId);

		list.append(stu);
	}

	fs.close();

	cout << "[INFO] Done" << endl;
}

