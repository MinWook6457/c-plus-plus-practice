
#include <iostream>

void main() {
	int number;
	std::cout << "구구단 숫자를 입력하세요 : ";
	std::cin >> number;

	for (int i = 1; i <= 9; i++) {
		std::cout << i << '*' << number <<':' << i * number<<std::endl;
	}
}