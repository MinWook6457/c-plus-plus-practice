
#include <iostream>
using namespace std;
int plusNum(int &ref) {
	ref++;
	return ref;
}
int changeNum(int& ref) {
	return -ref;
}
void main() {
	int num = 10;
	cout << "�߰� �Լ� ȣ�� �� : " << num << endl;
	num = plusNum(num);
	cout << "�߰� �Լ� ȣ�� �� : " << num << endl;
	num = changeNum(num);
	cout << "�߰� �Լ� ȣ�� �� : " << num << endl;
}