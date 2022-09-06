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
	int salary; // �� �޿�
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
	int payPerHour; // �ð��� �޿�
public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {

	}

	void AddWorkTime(int time) {
		workTime += time;
	}
	int getPay() const {
		return workTime * payPerHour; // �ð��� �޿� * ���� �ð�
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << getPay() << endl;
	}
};
class SalesWorker : public PermanentWorker { // getPay�� showSalaryInfo �Լ� �������̵�
private:
	int salesResult; // �� �ǸŽ���
	double bonusRatio; // �󿩱� ����
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
		//
	}

	void AddSalesResult(int value) {
		salesResult += value;
	}

	int getPay() const {
		return PermanentWorker::getPay() // PermanentWorker �� getPay ȣ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << getPay() << endl; // SalesWorker�� getPay ȣ��
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
	//���� ������ �������� ����� ��Ʈ�� Ŭ���� ��ü ����
	EmployeeHandler handler;

	//���� ���
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 2000));
	
	//�ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Hong", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//������ ���
	SalesWorker* seller = new SalesWorker("Jung", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo(); // �̹��޿� �����ؾ� �� �޿��� ����

	handler.ShowTotalSalary(); // �̹��� �޿��� ����
}


