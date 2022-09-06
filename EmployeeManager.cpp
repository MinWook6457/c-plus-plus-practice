
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
		// ������
	}
	void AddEmployee(PermanentWorker* emp) { // ���ο� ���� ���� ���
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const { // ��� ������ �̹� �� �޿� ���� ���
		for (int i = 0; i < empNum; i++) {
			empList[i]->showSalaryInfo();
		}
	}
	void ShowTotalSalary() const { // �̹� �� �޿��� �Ѿ� ���
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
	EmployeeHanlder hanlder; // ���� ������ �������� ����� ��Ʈ�� Ŭ���� ��ü ����

	//���� ���
	hanlder.AddEmployee(new PermanentWorker("kim", 1000));
	hanlder.AddEmployee(new PermanentWorker("lee", 2000));
	hanlder.AddEmployee(new PermanentWorker("park", 4000));

	hanlder.ShowAllSalaryInfo(); // �̹� �޿� �����ؾ� �� �޿��� ����

	hanlder.ShowTotalSalary(); // �̹� �޿� �����ؾ��� �޿��� ����
}