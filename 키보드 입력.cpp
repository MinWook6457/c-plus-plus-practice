
#include <iostream>

void main() {
	int val1;
	std::cout << "ù ��° ���� �Է� ";
	std::cin >> val1;

	int val2;
	std::cout << "�� ��° ���� �Է� ";
	std::cin >> val2;

	std::cout << "�������" << val1 + val2 << std::endl;
	std::cout << "Hello World" << val1 << val2 << std::endl;


	int x, y, result = 0;

	std::cout << "�� �� �Է� ";
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

	std::cout << "�� �� ���� ������ �� " << result << std::endl;
}