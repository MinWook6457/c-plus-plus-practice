
#include <iostream>

void main() {
	int val1;
	std::cout << "첫 번째 숫자 입력 ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자 입력 ";
	std::cin >> val2;

	std::cout << "덧셈결과" << val1 + val2 << std::endl;
	std::cout << "Hello World" << val1 << val2 << std::endl;


	int x, y, result = 0;

	std::cout << "두 수 입력 ";
	std::cin >> x >> y;

	if (x < y) {
		for (int i = x + 1;i < y;i++) {
			result += i;
		}
	}
	else {
		for (int i = y + 1;i < x;i++) {
			result += i;
		}
	}

	std::cout << "두 수 정수 사이의 합 " << result << std::endl;
}