#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
		//
	}

	void ShowPointPosition() const {
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}

	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this; // 객체 자기 자신 반환
	}

	friend Point& operator--(Point& ref); // 전역함수에 대하여 friend 선언
};

Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

void main() {
	Point pos(1, 2);
	++pos; // pos.operator++(); 으로 해석
	pos.ShowPointPosition(); 
	--pos; // operator--(pos); 으로 해석
	pos.ShowPointPosition();

	++(++pos); // -> ++(pos.operator++()) -> ++(pos의 참조 값) -> (pos의 참조 값).operator++();
	pos.ShowPointPosition();
	--(--pos); // -> --(operator--(pos)) -> --(pos의 참조 값) -> operator--(pos의 참조 값);
	pos.ShowPointPosition();
}
