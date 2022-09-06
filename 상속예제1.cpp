
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
	char major[50]; // 전공과목
public:
	UnivStudent(const char* myname, int myage, const char* major) : Person(myname, myage) { // 상속 받은 클래스의 모든 멤버를 초기화 해야함
		strcpy(this->major, major);									 // Person 클래스를 호출해서 멤버를 초기화함
	}
	void WhoYouAre() const {
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl;
	}
};
void main() {
	UnivStudent ustd1("Lee", 22, "컴퓨터 공학");
	ustd1.WhoYouAre();

	UnivStudent ustd2("Kim", 24, "전기 공학");
	ustd2.WhoYouAre();
}