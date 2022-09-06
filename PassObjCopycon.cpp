
#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		// empty
	}

	SoSimple(const SoSimple& sim) : num(sim.num) {
		cout << "Called SoSimple (const SoSimple& sim)" << endl;
	}
	void showData() {
		cout << num << endl;
	}
};

void SimpleFuncObj(SoSimple obj) {
	obj.showData();
}

void main() {
	SoSimple obj(7);
	cout << "�Լ� ȣ�� ��" << endl;
	SimpleFuncObj(obj);
	cout << "�Լ� ȣ�� ��" << endl;

}