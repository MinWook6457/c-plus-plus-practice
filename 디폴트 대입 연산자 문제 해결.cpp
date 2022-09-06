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
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;

	}
	Person& operator = (const Person& ref) { // ���� ������ �����ε����� �ذ�
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
	man2 = man1; // ���Կ����� ȣ�� �׷��� Person Ŭ�������� ���� �����ڰ� ���ǵǾ� ���� �����Ƿ� ����Ʈ ���Կ����� ȣ��(����� ���)
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// called destructor! �� �� �� ȣ�� �Ǿ����� �̴� ȣ�� ������ ������ ����
	// ���� : 32���� ��������
	// man2�� ����Ű�� ���ڿ� �ּҰ��� ����
	// ���� ����� ���� ��ü �Ҹ�������� ������ ���ڿ��� �ߺ� �Ҹ��ϴ� ���� �߻� -> �޸� ����
}
