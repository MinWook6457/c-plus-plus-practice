#include <iostream>

void main() {
	for (;;) {
		int money;
		int sum = 50;
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> money;
		if (money == -1) {
			std::cout << "���α׷��� �����մϴ�.";
			return;
		}
		else {
			sum = sum + (money * 12 / 100);
		}
		std::cout << "�̹��� �޿� : " << sum << std::endl;
	}
}