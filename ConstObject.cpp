
// const Ű���尡 ��ü�� �ٰ� �Ǹ� ��ü�� ������δ� const ����Լ��� ȣ���� �����ϴ�.
#include <iostream>
using namespace std;
class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		// empty
	}

	 SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}

	void showData() const {
		cout << "num :" << num << endl;
	} 
};
void main() {
	const SoSimple obj(7); // ��ü�� ������ ������ ������� ����
	obj.showData();
}