#include <iostream>
using namespace std;

class Point {
private: 
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle {
private:
	int radius;
	Point Center;
public:
	void Init(int x, int y, int r) {
		Center.Init(x, y);
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
	void Init(int inX, int inY, int inR, int outX, int outY, int outR) {
		inCircle.Init(inX, inY, inR);
		outCircle.Init(outX, outY, outR);
	}
	void showRingInfo() const {
		cout << "Inner Circle Info ... " << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info ... " << endl;
		outCircle.ShowCircleInfo();

	}
};
void main() {
	Ring ring;
	ring.Init(1,1,4,2,2,9);
	ring.showRingInfo();
}