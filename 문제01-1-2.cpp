
#include <iostream>
void main() {
	char name[100];
	char num[100];
	std::cout << "이름을 입력하세요 :";
	std::cin >> name;

	std::cout << "전화번호를 입력하세요 :";
	std::cin >> num;

	std::cout << "이름 : " << name << " 번호 : " << num << std::endl;
}