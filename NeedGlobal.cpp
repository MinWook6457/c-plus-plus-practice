#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple {
public:
	SoSimple() {
		simObjCnt++;
		cout << simObjCnt << "¹ø Â° SoSimple°´Ã¼" << endl;
	}
};
class SoComplex {
public:
	SoComplex() {
		cmxObjCnt++;
		cout << cmxObjCnt << "¹ø Â° SoComplex°´Ã¼" << endl;
	}
	SoComplex(SoComplex &copy) {
		cmxObjCnt++;
		cout << cmxObjCnt << "¹ø Â° SoComplex°´Ã¼" << endl;
	}
};
void main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
}