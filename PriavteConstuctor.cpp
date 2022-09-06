#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA() : num(0){} // num의 값을 0으로 초기화 , 디폴트 생성자
	AAA& CreateInitObj(int n)const {
		AAA *ptr = new AAA(n);
		return *ptr;
	}
	void showNum() const { cout << num << endl; }

private:
	AAA(int n) : num(n){} // num의 값을 n으로 초기화
};

void main() {
	AAA base;
	base.showNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.showNum();

	delete& obj1;
}