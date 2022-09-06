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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
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
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}

};
void main() {
	MyFriendDetailInfo friend1("김진성", 22, "충남 아산", "010-9585-9994");
	MyFriendDetailInfo friend2("김민욱", 23, "경기 수원", "010-3953-2632");
	friend1.ShowMyFriendDetailInfo();
	friend2.ShowMyFriendDetailInfo();
}