#include <iostream>
namespace BestComImpl {
	void SimpleFunc() {
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}
namespace ProgComImpl {
	void SimpleFunc() {
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}
void main() {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
}
