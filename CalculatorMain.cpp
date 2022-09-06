
#include <iostream>
#include "Calculator.h"
using namespace std;
void main() {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.sub(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.div(4.9, 1.2) << endl;
	cal.ShowOpCount();
}
