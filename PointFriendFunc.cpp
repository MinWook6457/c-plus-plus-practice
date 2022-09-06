
#include <iostream>
using namespace std;

class Point;

class PointOP {
private: 
	int opcnt;
public:
	PointOP() : opcnt(0) {
		// ����Ʈ
	}
	Point PointAdd(const Point&, const Point&);
	Point PointSub(const Point&, const Point&);
	~PointOP()
	{
		cout << "Operation times : " << opcnt << endl;
	}
};

class Point {
private:
	int x, y;
public:
	Point(const int& xpos, const int& ypos) : x(xpos), y(ypos) {

	}
	friend Point PointOP:: PointAdd(const Point&, const Point&);
	friend Point PointOP:: PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);
};
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}
void main() {
	Point pos1(1, 2);
	Point pos2(2, 4);

	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
}
void ShowPointPos(const Point& pos) {
	cout << "[" << pos.x << "," << pos.y << "]" << endl;
}