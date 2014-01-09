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

void Utility::queryById() {
	string id;
	int ix = -1;
	Student *pTempStu;

	while(true) {
		cout << "请输入学号>";
		cin >> id;
		ix = list.queryById(id);

		if(-1 != ix) {
			pTempStu = &((list.getElements())[ix]);
			cout << "\tId\tName\tRoomId" << endl;
			cout << *pTempStu << endl;
			break;
		}

		cout << "该学号不存在" << endl;
	}
}

void queryByName() {
}

void queryByRoomId() {
}

void Utility::pause() {
	cout << "Press any key to continue..." << endl;
	getchar();
	getchar();
}

void Utility::showMenu() {
	cout << "\t1. 按学号查询" << endl;
	cout << "\t2. 按姓名查询" << endl;
	cout << "\t3. 按宿舍号查询" << endl;
	cout << "\t4. Exit" << endl;
}

// Main lifecycle method
int Utility::exec() {
	readDataFromFile("data.dat", list);

	char choose = 0;
	while(true) {
		showMenu();
		cin >> choose;

		switch(choose) {
			case '1': // ID
				queryById();
				pause();
				break;

			case '2': // Name
				//queryByName();
				pause();
				break;

			case '3': // RoomId
			  	//queryByRoomId();
				pause();
				break;

			case '4':
				return 0;
				pause();
				break;

			default:
				cout << "请重新输入" << endl;
				pause();
				break;
		}
	}

	return 0;
}

