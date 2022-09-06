
#include <iostream>
#include <cstring>
#include <conio.h>
#pragma warning(disable:4996)
using namespace std;
char Menu() {
	cout << "1. 전화번호 등록" << endl;
	cout << "2. 전화번호 출력" << endl;
	cout << "3. 전화번호 검색" << endl;
	cout << "4. 전화번호 삭제" << endl;
	cout << "0. 프로그램 종료" << endl;
	return getch();
}
class PhoneNum {
private:
	char* name;
	char* num;
public:
	void input(char* bufname = 0, char* bufnum = 0) {
		name = bufname;
		num = bufnum;
	}
	char* getName() {
		return name;
	}
	char* getNum() {
		return num;
	}
};
class NumBook {
private :
	PhoneNum index[100];
	int count;
public:
	NumBook() {
		count = 0;
	}
	void WritePhoneNum() {
		if (count == 0) {
			cout << "이름을 입력하시고 띄어쓰기 후 번호를 입력하세요" << endl;
			cout << "예: 홍길동 010-1234-5678" << endl;
		}

		char _bufname[100];
		char _bufnum[100];

		cout << "이름 / 번호 입력 : ";
		char* bufname = new char[strlen(_bufname) + 1];
		char* bufnum = new char[strlen(_bufnum) + 1];

		cin >> bufname >> bufnum;
		index[count++].input(bufname, bufnum);

	}
	void printNum() {
		for (int i = 0; i < count; i++) {
			cout << index[i].getName() << ":" << index[i].getNum() << endl;
		}
	}
	void Search() {
		cout << "1.번호 검색" << endl << "2.이름 검색" << endl;
		switch (getch())
		{
		case '1':
			char searchNum[100];
			cout << "검색할 번호를 입력하세요 : ";
			cin >> searchNum;
			for (int i = 0; i < count; i++) {
				if (strcmp(index[i].getNum(), searchNum) == 0) {
					cout << index[i].getName() << ":" << index[i].getNum() << endl;
				}
			}
			break;
		case '2':
			char searchName[100];
			cout << "검색할 이름를 입력하세요 : ";
			cin >> searchName;
			for (int i = 0; i < count; i++) {
				if (strcmp(index[i].getName(), searchName) == 0) {
					cout << index[i].getName() << ":" << index[i].getNum() << endl;
				}
			}
			break;
		}
	}
	void Delete() {
		char deleteName[100];
		cout << "삭제할 이름을 입력하세요 :";
		cin >> deleteName;
		for (int i = 0; i < count; i++) {
			if (strcmp(index[i].getName(), deleteName) == 0) {
				delete[] index[i].getName();
				delete[] index[i].getNum();
				index[i].input(index[i + 1].getName(), index[i].getNum());
				count--;
			}
		}
	}
	void DeleteHeap() {
		for (int i = 0; i < count; i++) {
			delete[] index[i].getName();
			delete[] index[i].getNum();
		}
	}
};
void main() {
	NumBook nb;
	bool run = true;
	while (run) {
		switch (Menu())
		{
		case '1':
			nb.WritePhoneNum();
			break;
		case '2':
			nb.printNum();
			break;
		case '3':
			nb.Search();
			break;
		case '4':
			nb.Delete();
			break;
		case '0':
			run = false;
			break;
		}
	}
	nb.DeleteHeap();
}