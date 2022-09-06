
#include <iostream>
#include "Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0) {
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}
// get set 함수는 액세스 함수임
int Point::getX() const { // const 정의의 이유 : 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다라는 의미임
	return x;
}

int Point::getY() const {
	return y;
}

bool Point::setX(int xpos) {
	if (xpos < 0 || xpos > 100) {
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::setX(int ypos) {
	if (ypos < 0 || ypos > 100) {
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	y = ypos;
	return true;
}
