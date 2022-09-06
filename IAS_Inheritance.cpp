#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class Computer {
private:
	char *owner;
public:
	Computer(const char* name) {
		owner = new char[strlen(name) + 1];
		strcpy(owner, name);
	}
	void Calculate() {
		cout << "요청 내용을 계산합니다" << endl;
	}
	~Computer() {
		delete[] owner;
	}
};

class NoteBookComputer : public Computer {
private:
	int Battery;
public:
	NoteBookComputer(const char* name, int initCharge) : Computer(name), Battery(initCharge) {
		//
	}

	void Charging() {
		Battery += 5;
	}

	void UseBattery() {
		Battery -= 1;
	}

	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "충전이 필요합니다" << endl;
			return;
		}
		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() {
		return Battery;
	}
};
class TableNoteBook : public NoteBookComputer {
private:
	char *regstPenModel;
public:
	TableNoteBook(const char* name, int initCharge, const char* pen) :NoteBookComputer(name,initCharge)  {
		regstPenModel = new char[strlen(pen) + 1];
		strcpy(regstPenModel, pen);
	}

	void Write(const char* penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "충전이 필요합니다" << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
	~TableNoteBook() {
		delete[] regstPenModel;
	}
};
void main() {
	NoteBookComputer nc("김민욱", 5);
	TableNoteBook tn("이국종", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
}