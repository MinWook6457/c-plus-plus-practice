
#include <iostream>
#define MAX 100
void main() {
	char name[MAX];
	char lang[MAX];

	std::cout << "�̸��� �����Դϱ�?";
	std::cin >> name;

	std::cout << "���� �����ϴ� ���� �����Դϱ�?";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�." << std::endl;
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;
}