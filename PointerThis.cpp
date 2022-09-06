
#include <iostream>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		cout << "num " << num << ", ";
		cout << "address = " << this << endl;
	}

	void showSimpleData() {
		cout << num << endl;
	}

	SoSimple* getThisPointer() {
		return this;
	}
};

void main() {
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.getThisPointer();	// 按眉俊 林家蔼 历厘
	cout << ptr1 << ", ";
	ptr1->showSimpleData();
}