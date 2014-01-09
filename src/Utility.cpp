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
		cout << "[INFO] 请输入学号>";
		cin >> id;
		ix = list.queryById(id);

		if(-1 != ix) {
			pTempStu = &((list.getElements())[ix]);
			printTableHeader();
			cout << *pTempStu << endl;
			break;
		}

		cout << "[ERROR] 该学号不存在" << endl;
	}
}

void Utility::queryByName() {
	string name;
	int ix = -1;
	Student *pTempStu;
	
	while(true) {
		cout << "[INFO] 请输入姓名>";
		cin >> name;
		ix = list.queryByName(name);

		if(-1 != ix) {
			pTempStu = &((list.getElements())[ix]);
			printTableHeader();
			cout << *pTempStu << endl;
			break;
		}

		cout << "[ERROR] 该姓名不存在" << endl;
	}
}

void Utility::queryByRoomId() {
	string roomId;
	int ix = -1;
	Student *pTempStu;

	while(true) {
		cout << "[INFO] 请输入房间号>";
		cin >> roomId;
		ix = list.queryByRoomId(roomId);

		if(-1 != ix) {
			pTempStu = &((list.getElements())[ix]);
			printTableHeader();
			cout << *pTempStu << endl;
			break;
		}

		cout << "[ERROR] 该房间不存在" << endl;
	}
}

void Utility::printTableHeader() {
	cout << "\tId\tName\tRoomId" << endl;
}

void Utility::pause() {
	//cout << "Press any key to continue..." << endl;
	getchar();
	getchar();
}

void Utility::showMenu() {
	cout << "\t------------------" << endl;
	cout << "\t1. 按学号查询" << endl;
	cout << "\t2. 按姓名查询" << endl;
	cout << "\t3. 按宿舍号查询" << endl;
	cout << "\t4. 查看所有数据" << endl;
	cout << "\t5. Exit" << endl;
	cout << "请选择>";
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
				queryByName();
				pause();
				break;

			case '3': // RoomId
			  	queryByRoomId();
				pause();
				break;

			case '4': // print all elements
				cout << list << endl;
				pause();
				break;

			case '5': // Exit program
				return 0;

			default:
				cout << "请重新输入" << endl;
				pause();
				break;
		}
	}

	return 0;
}

