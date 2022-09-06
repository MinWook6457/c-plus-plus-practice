
#include <iostream>

void main() {
	int x, result = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "번 째 정수 입력 : ";
		std::cin >> x;
		result += x;
	}
	std::cout << "합계 : " << result << std::endl;
}
