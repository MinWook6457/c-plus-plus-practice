
#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
class Person {
private:
	int age;
	char name[50];
public:
	Person(const char* name, int myage) : age(myage) {
		strcpy(this->name, name);
	}
	void WhatYourName() const {
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const {
		cout << "My age is " << age << endl;
	}
};
class UnivStudent : public Person {
private:
	char major[50]; // ��������
public:
	UnivStudent(const char* myname, int myage, const char* major) : Person(myname, myage) { // ��� ���� Ŭ������ ��� ����� �ʱ�ȭ �ؾ���
		strcpy(this->major, major);									 // Person Ŭ������ ȣ���ؼ� ����� �ʱ�ȭ��
	}
	void WhoYouAre() const {
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl;
	}
};
void main() {
	UnivStudent ustd1("Lee", 22, "��ǻ�� ����");
	ustd1.WhoYouAre();

	UnivStudent ustd2("Kim", 24, "���� ����");
	ustd2.WhoYouAre();
}