
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

	Point& operator++() { // ��������
		xpos += 1;
		ypos += 1;
		return *this;
	}
	// Point Ŭ������ ����Լ� const�� ������ ������ (pos++)++ �� (pos--)--�� ������ ���� ���� ����
	const Point operator++(int) { // ��������
		const Point retobj(xpos, ypos); // const Point retobj(*this); �Լ� ������ retobj�� ������ ���ڴ�
		xpos += 1;
		ypos += 1;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point& operator--(Point& ref,int);
};
Point& operator--(Point& ref) { // ��������
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
const Point& operator--(Point& ref, int) { // ��������
	const Point retobj(ref); // const ��ü�� �Ѵ�. �Լ� ������ retobj�� ������ ���ڴ�
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}
void main() {
	Point pos(3, 5); //const Point pos(3,4) -> pos��ü ���ȭ, pos�� ���� ���x
	Point cpy;
	cpy = pos--;
	cpy.ShowPointPosition();
	pos.ShowPointPosition();

	cpy = pos++;
	cpy.ShowPointPosition();
	pos.ShowPointPosition();
}