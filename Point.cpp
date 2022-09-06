
#include <iostream>
#include "Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0) {
		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}
// get set �Լ��� �׼��� �Լ���
int Point::getX() const { // const ������ ���� : �Լ� �������� ��������� ����� ���� �������� �ʰڴٶ�� �ǹ���
	return x;
}

int Point::getY() const {
	return y;
}

bool Point::setX(int xpos) {
	if (xpos < 0 || xpos > 100) {
		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::setX(int ypos) {
	if (ypos < 0 || ypos > 100) {
		cout << "��� ������ �� ����" << endl;
		return false;
	}

	y = ypos;
	return true;
}
