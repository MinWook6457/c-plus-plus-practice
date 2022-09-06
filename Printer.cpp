#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Printer {
private:
	char str[30];
public:
	void SetString(const char* s);
	void ShowString();
};

void Printer::SetString(const char* s) {
	strcpy(str, s);
}
void Printer::ShowString() {
	cout << str << endl;
}

void main() {
	Printer pnt;
	pnt.SetString("HelloWorld!");
	pnt.ShowString();

	pnt.SetString("I LOVE C++");
	pnt.ShowString();
}