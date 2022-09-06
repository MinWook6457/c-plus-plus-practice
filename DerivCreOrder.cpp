
#include <iostream>
using namespace std;

class SoBase {
private:
	int baseNum;
public:
	SoBase() : baseNum(20) {
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n) {
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData() {
		cout << baseNum << endl;
	}
};

class SoDrived : public SoBase {
private:
	int derivNum;
public:
	SoDrived() : derivNum(30) {
		cout << "SoDrived()" << endl;
	}
	SoDrived(int n) : derivNum(n) {
		cout << "SoDrived(int n)" << endl;
	}
	SoDrived(int n1,int n2) : SoBase(n1), derivNum(n2) {
		cout << "SoDrived(int n1,int n2)" << endl;
	}
	void ShowDerivData() {
		ShowBaseData();
		cout << derivNum << endl;
	}
};
void main() {
	cout << "case1...... " << endl;
	SoDrived dr1;
	dr1.ShowDerivData();
	cout << "--------------------------" << endl;
	cout << "case2...... " << endl;
	SoDrived dr2(12);
	dr2.ShowDerivData();
	cout << "--------------------------" << endl;
	cout << "case3...... " << endl;
	SoDrived dr3(23, 24);
	dr3.ShowDerivData();
}