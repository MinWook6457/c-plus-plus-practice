#include <iostream>
using namespace std;

class TwoNumber {
private:
	int num1, num2;
public:
	TwoNumber(int num1, int num2) {
		this->num1 = num1;
		this->num2 = num2;
	}

	void showTwoNumber() {
		cout << this->num1 << " , " << this->num2 << endl;
	}
};
void main() {
	TwoNumber two(2, 4);
	two.showTwoNumber();
}