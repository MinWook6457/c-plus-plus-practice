
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
	cout << "추가 함수 호출 전 : " << num << endl;
	num = plusNum(num);
	cout << "추가 함수 호출 후 : " << num << endl;
	num = changeNum(num);
	cout << "추가 함수 호출 후 : " << num << endl;
}