#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA() : num(0){} // num�� ���� 0���� �ʱ�ȭ , ����Ʈ ������
	AAA& CreateInitObj(int n)const {
		AAA *ptr = new AAA(n);
		return *ptr;
	}
	void showNum() const { cout << num << endl; }

private:
	AAA(int n) : num(n){} // num�� ���� n���� �ʱ�ȭ
};

void main() {
	AAA base;
	base.showNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.showNum();

	delete& obj1;
}