
#include <iostream>
#define MAX 100
void main() {
	char name[MAX];
	char lang[MAX];

	std::cout << "이름은 무엇입니까?";
	std::cin >> name;

	std::cout << "가장 좋아하는 언어는 무엇입니까?";
	std::cin >> lang;

	std::cout << "내 이름은 " << name << "입니다." << std::endl;
	std::cout << "가장 좋아하는 언어는 " << lang << "입니다." << std::endl;
}