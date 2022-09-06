#include <iostream>

void main() {
	for (;;) {
		int money;
		int sum = 50;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> money;
		if (money == -1) {
			std::cout << "프로그램을 종료합니다.";
			return;
		}
		else {
			sum = sum + (money * 12 / 100);
		}
		std::cout << "이번달 급여 : " << sum << std::endl;
	}
}