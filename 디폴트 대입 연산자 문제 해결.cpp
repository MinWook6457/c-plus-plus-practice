#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;

	}
	Person& operator = (const Person& ref) { // 대입 연산자 오버로딩으로 해결
		delete[] name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
	~Person() {
		delete[]name;
		cout << "called destructor!";
	}
};

void main() {
	Person man1("Kim Min Wook", 22);
	Person man2("Choi An Yong", 26);
	man2 = man1; // 대입연산자 호출 그러나 Person 클래스에는 대입 연산자가 정의되어 있지 않으므로 디폴트 대입연산자 호출(멤버대 멤버)
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// called destructor! 이 한 번 호출 되었으나 이는 호출 과정에 문제가 있음
	// 문제 : 32행의 얕은복사
	// man2가 가리키던 문자열 주소값을 잃음
	// 얕은 복사로 인해 객체 소멸과정에서 지워진 문자열을 중복 소멸하는 문제 발생 -> 메모리 누수
}
