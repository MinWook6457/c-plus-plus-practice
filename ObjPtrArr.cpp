
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;
class Person {
private:
	char* name;
	int age;
public:
	Person(char* myName, int myAge) {
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}

	Person() {
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void setPersonInfo(char* myName, int myAge) {
		name = myName;
		age = myAge;
	}
	void showPersonInfo() const {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}

	~Person() {
		delete[]name;
		cout << "called ~Destructor()" << endl;
	}
};

void main() {
	Person* person[3];
	char name[100];
	int age;

	for (int i = 0; i < 3; i++) {
		cout << "�̸� : ";
		cin >> name;
		cout << "���� : ";
		cin >> age;

		person[i] = new Person(name, age);
	}
	for (int i = 0; i < 3; i++) {
		person[i]->showPersonInfo();
		delete person[i];
	}

}