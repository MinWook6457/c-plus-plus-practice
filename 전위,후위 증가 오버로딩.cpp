
#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {
		//
	}

	void ShowPointPosition() const {
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}

	Point& operator++() { // 전위증가
		xpos += 1;
		ypos += 1;
		return *this;
	}
	// Point 클래스의 멤버함수 const로 선언한 이유는 (pos++)++ 및 (pos--)--를 컴파일 에러 내기 위함
	const Point operator++(int) { // 후위증가
		const Point retobj(xpos, ypos); // const Point retobj(*this); 함수 내에서 retobj의 변경을 막겠다
		xpos += 1;
		ypos += 1;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point& operator--(Point& ref,int);
};
Point& operator--(Point& ref) { // 전위감소
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
const Point& operator--(Point& ref, int) { // 후위감소
	const Point retobj(ref); // const 객체라 한다. 함수 내에서 retobj의 변경을 막겠다
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}
void main() {
	Point pos(3, 5); //const Point pos(3,4) -> pos객체 상수화, pos값 변경 허용x
	Point cpy;
	cpy = pos--;
	cpy.ShowPointPosition();
	pos.ShowPointPosition();

	cpy = pos++;
	cpy.ShowPointPosition();
	pos.ShowPointPosition();
}