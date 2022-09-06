
#include <iostream>
using namespace std;
#include "Calculator.h"
double Calculator::add(double x, double y) {
	a++;
	return x + y;
}
double Calculator::sub(double x, double y) {
	s++;
	return x - y;
	
}
double Calculator::mul(double x, double y) {
	m++;
	return x * y;
}
double Calculator::div(double x, double y) {
	d++;
	return x / y;
}
void Calculator::Init() {
	x = 0;
	y = 0;
}
void Calculator::ShowOpCount() {
	cout << "µ¡¼À : " << a << "»¬¼À : " << s << "°ö¼À : " << m << "³ª´°¼À : " << d << endl;
}


