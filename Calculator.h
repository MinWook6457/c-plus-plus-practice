#ifndef  __CAL_H__
#endif // ! __CAL_H__

class Calculator {
private:
	double x, y;
	int a = 0, s = 0, m = 0, d = 0;
public:
	double add(double x, double y);
	double sub(double x, double y);
	double mul(double x, double y);
	double div(double x, double y);
	void ShowOpCount();
	void Init();
};