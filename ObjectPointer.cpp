
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
	Person* ptr1 = new Student(); // 객체 포인터 변수 : Student는 Person을 상속하므로 Person형 포인터는 Student객체를 가리킬 수 있음
	Person* ptr2 = new PartTimeStudent(); // PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킨다.
	Student* ptr3 = new PartTimeStudent(); // PartTimeStudent는 Student를 상속하므로 Student형 포인터는 PartTimeStudent 객체를 가리킬 수 있음.

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1, delete ptr2, delete ptr3;
}