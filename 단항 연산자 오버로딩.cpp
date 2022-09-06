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
		return *this; // ��ü �ڱ� �ڽ� ��ȯ
	}

	friend Point& operator--(Point& ref); // �����Լ��� ���Ͽ� friend ����
};

Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

void main() {
	Point pos(1, 2);
	++pos; // pos.operator++(); ���� �ؼ�
	pos.ShowPointPosition(); 
	--pos; // operator--(pos); ���� �ؼ�
	pos.ShowPointPosition();

	++(++pos); // -> ++(pos.operator++()) -> ++(pos�� ���� ��) -> (pos�� ���� ��).operator++();
	pos.ShowPointPosition();
	--(--pos); // -> --(operator--(pos)) -> --(pos�� ���� ��) -> operator--(pos�� ���� ��);
	pos.ShowPointPosition();
}
