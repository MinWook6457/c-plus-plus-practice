#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* fname, int fage) :age(fage) {
		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}
	void ShowMyFriendInfo() {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~MyFriendInfo() {
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* fname, int fage, const char* adr, const char* pnum) :MyFriendInfo(fname, fage) {
		addr = new char[strlen(adr) + 1];
		phone = new char[strlen(pnum) + 1];
		strcpy(addr, adr);
		strcpy(phone, pnum);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "�ּ� : " << addr << endl;
		cout << "��ȭ : " << phone << endl;
	}

};
void main() {
	MyFriendDetailInfo friend1("������", 22, "�泲 �ƻ�", "010-9585-9994");
	MyFriendDetailInfo friend2("��ο�", 23, "��� ����", "010-3953-2632");
	friend1.ShowMyFriendDetailInfo();
	friend2.ShowMyFriendDetailInfo();
}