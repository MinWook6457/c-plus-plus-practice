
#include <iostream>
#include <cstring>
#include <conio.h>
#pragma warning(disable:4996)
using namespace std;
char Menu() {
	cout << "1. ��ȭ��ȣ ���" << endl;
	cout << "2. ��ȭ��ȣ ���" << endl;
	cout << "3. ��ȭ��ȣ �˻�" << endl;
	cout << "4. ��ȭ��ȣ ����" << endl;
	cout << "0. ���α׷� ����" << endl;
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
			cout << "�̸��� �Է��Ͻð� ���� �� ��ȣ�� �Է��ϼ���" << endl;
			cout << "��: ȫ�浿 010-1234-5678" << endl;
		}

		char _bufname[100];
		char _bufnum[100];

		cout << "�̸� / ��ȣ �Է� : ";
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
		cout << "1.��ȣ �˻�" << endl << "2.�̸� �˻�" << endl;
		switch (getch())
		{
		case '1':
			char searchNum[100];
			cout << "�˻��� ��ȣ�� �Է��ϼ��� : ";
			cin >> searchNum;
			for (int i = 0; i < count; i++) {
				if (strcmp(index[i].getNum(), searchNum) == 0) {
					cout << index[i].getName() << ":" << index[i].getNum() << endl;
				}
			}
			break;
		case '2':
			char searchName[100];
			cout << "�˻��� �̸��� �Է��ϼ��� : ";
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
		cout << "������ �̸��� �Է��ϼ��� :";
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