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
		cout << "��û ������ ����մϴ�" << endl;
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
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
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
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
	~TableNoteBook() {
		delete[] regstPenModel;
	}
};
void main() {
	NoteBookComputer nc("��ο�", 5);
	TableNoteBook tn("�̱���", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
}