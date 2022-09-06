
#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y){}
	void ShowPointInfo() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle {
private:
	int radius;
	Point Center;
public:
	Circle(int x, int y, int r) : Center(x, y) {
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius : " << radius << endl;
		Center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inCircle;
	Circle outCircle;

public:
	Ring(int inX, int inY, int inR, int outX, int outY, int outR) : inCircle(inX, inY, inR), outCircle(outX, outY, outR)
	{
	}
	void showRingInfo() const {
		cout << "Inner Circle Info ... " << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info ... " << endl;
		outCircle.ShowCircleInfo();

	}
};
void main() {
	Ring ring(1,1,4,2,2,9);
	ring.showRingInfo();
}
