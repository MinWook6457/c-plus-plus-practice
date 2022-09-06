
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Person {
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person {
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student {
public:
	void Work() {
		cout << "Work" << endl;
	}
};

void main() {
	Person* ptr1 = new Student(); // ��ü ������ ���� : Student�� Person�� ����ϹǷ� Person�� �����ʹ� Student��ü�� ����ų �� ����
	Person* ptr2 = new PartTimeStudent(); // PartTimeStudent�� Person�� ���� ����ϹǷ�, Person�� ������ ������ PartTimeStudent ��ü�� ����Ų��.
	Student* ptr3 = new PartTimeStudent(); // PartTimeStudent�� Student�� ����ϹǷ� Student�� �����ʹ� PartTimeStudent ��ü�� ����ų �� ����.

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1, delete ptr2, delete ptr3;
}