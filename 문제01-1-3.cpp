
#include <iostream>

void main() {
	int number;
	std::cout << "������ ���ڸ� �Է��ϼ��� : ";
	std::cin >> number;

	for (int i = 1; i <= 9; i++) {
		std::cout << i << '*' << number <<':' << i * number<<std::endl;
	}
}