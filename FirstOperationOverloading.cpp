
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class First {
private:
	int num1, num2;	
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {
		//
	}

	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}
};

class Second {
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4) {
		//
	}
	void ShowData() {
		cout << num3 << ", " << num4 << endl;
	}

	Second& operator = (const Second& ref) {
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

void main() {
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc; // fcpy.operator=(fsrc) 로 해석된다. 이로 인해 디폴트로 삽입된 대입 연산자 호출
	scpy = ssrc; // scpy.operator=(ssrc) 로 해석된다. 이로 인해 디폴트로 삽입된 대입 연산자 호출

	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;

	fob1 = fob2 = fsrc; // 결합 방향에 의해 오른쪽에서 왼쪽으로 진행된다. 동일한 자료형의 두 객체간의 대입연산 허용
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
}