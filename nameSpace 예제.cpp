#include <iostream>
namespace BestComImpl {
	void SimpleFunc() {
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}
namespace ProgComImpl {
	void SimpleFunc() {
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}
void main() {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
}
