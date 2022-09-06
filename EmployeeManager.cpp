
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
class PermanentWorker {
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money) :salary(money) {
		strcpy(this->name, name);
	}
	int getPay() const {
		return salary;
	}
	void showSalaryInfo() const{
		cout << "name : " << name << endl;
		cout << "salary : " << getPay() << endl << endl;
	}
};
class EmployeeHanlder {
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHanlder() : empNum(0) {
		// 생성자
	}
	void AddEmployee(PermanentWorker* emp) { // 새로운 직원 정보 등록
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const { // 모든 직원의 이번 달 급여 정보 출력
		for (int i = 0; i < empNum; i++) {
			empList[i]->showSalaryInfo();
		}
	}
	void ShowTotalSalary() const { // 이번 달 급여의 총액 출력
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getPay();
		}
		cout << "Salary sum = " << sum << endl;
	}
	~EmployeeHanlder() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

void main() {
	EmployeeHanlder hanlder; // 직원 관리를 목적으로 설계된 컨트롤 클래스 객체 생성

	//직원 등록
	hanlder.AddEmployee(new PermanentWorker("kim", 1000));
	hanlder.AddEmployee(new PermanentWorker("lee", 2000));
	hanlder.AddEmployee(new PermanentWorker("park", 4000));

	hanlder.ShowAllSalaryInfo(); // 이번 달에 지불해야 할 급여의 정보

	hanlder.ShowTotalSalary(); // 이번 달에 지불해야할 급여의 총합
}