#include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() {
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc" << endl;
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc" << endl;
	}
};
void main() {
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj; // obj는 Second를 상속하는 Third 객체이므로 Second형으로 참조가능함
	sref.FirstFunc();  // 컴파일러는 참조자의 자료형을 가지고 함수 호출 가능성을 판단하기 때문에 FirstFunc,SecondFunc 호출 가능
	sref.SecondFunc(); // 그러나 ThirdFunc는 Third클래스에 정의되어 있기 때문에 호출 불가능
	sref.SimpleFunc(); // SimpleFunc는 가상함수이므로 Third클래스에 정의된 SimpleFunc 함수 호출

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
}