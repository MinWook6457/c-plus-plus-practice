#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {

	}

	SoSimple(const SoSimple& sim) : num(sim.num) {
		cout << "Called SoSimple(const SoSimple &sim)" << endl;
	}
	SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}
	void ShowData() {
		cout << num << endl;
	}
};
SoSimple SimpleFuncObj(SoSimple obj) {
	cout << "return ÀÌÀü" << endl;
	return obj;
}
void main() {
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();

}