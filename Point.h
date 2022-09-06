#ifndef __POINT_H__

#endif // !__POINT_H__

class Point {
private:
	int x, y;
public:
	bool InitMembers(int xpos, int ypos);
	int getX() const;
	int getY() const;
	bool setX(int xpos);
	bool setY(int ypos);
};