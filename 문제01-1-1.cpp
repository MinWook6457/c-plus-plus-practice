
#include <iostream>

void main() {
	int x, result = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "�� ° ���� �Է� : ";
		std::cin >> x;
		result += x;
	}
	std::cout << "�հ� : " << result << std::endl;
}
