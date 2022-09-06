
#include <iostream>
using namespace std;
void SwapPointer(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void main() {
	int num1 = 5;
	int* ptr1 = &num1;

	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout << num1 << " " << num2 << endl;
}