#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name : " << name << endl;
	}
	virtual int getPay() const {
		return 0;
	}
	virtual void ShowSalaryInfo() const {
		//
	}
};

class PermanentWorker : public Employee {
private:
	int salary; // 월 급여
public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money) {
		//
	}

	int getPay() const {
		return salary;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " <<getPay() << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour; // 시간당 급여
public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {

	}

	void AddWorkTime(int time) {
		workTime += time;
	}
	int getPay() const {
		return workTime * payPerHour; // 시간당 급여 * 일한 시간
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << getPay() << endl;
	}
};
class SalesWorker : public PermanentWorker { // getPay와 showSalaryInfo 함수 오버라이딩
private:
	int salesResult; // 월 판매실적
	double bonusRatio; // 상여금 비율
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
		//
	}

	void AddSalesResult(int value) {
		salesResult += value;
	}

	int getPay() const {
		return PermanentWorker::getPay() // PermanentWorker 의 getPay 호출
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << getPay() << endl; // SalesWorker의 getPay 호출
	}
};
class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {

	}

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getPay();
		}
		cout << "Salary Sum : " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

void main() {
	//직원 관리를 목적으로 설계된 컨트롤 클래스 객체 생성
	EmployeeHandler handler;

	//직원 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 2000));
	
	//임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Hong", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직 등록
	SalesWorker* seller = new SalesWorker("Jung", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo(); // 이번달에 지급해야 할 급여의 정보

	handler.ShowTotalSalary(); // 이번달 급여의 총합
}


