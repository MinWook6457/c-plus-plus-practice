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
	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator *(int times, Point& ref);
};
Point operator *(int times, Point& ref) {
	return ref * times;
}

void main() {
	Point pos(1, 2);
	Point copy;

	copy = 3 * pos;
	copy.ShowPointPosition();

	copy = 2 * pos * 3;
	copy.ShowPointPosition();
}