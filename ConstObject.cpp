
// const 키워드가 객체에 붙게 되면 객체를 대상으로는 const 멤버함수만 호출이 가능하다.
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
	const SoSimple obj(7); // 객체의 데이터 변경을 허용하지 않음
	obj.showData();
}