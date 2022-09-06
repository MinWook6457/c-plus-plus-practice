
#include <iostream>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

const int NAME_LEN = 20;

void ShowMenu();			// �޴����
void MakeAccount();		// ���°����� ���� �Լ�
void DepositMoney();		// ��	��
void WithDrawMoney();		// ��	��
void ShowAllAccInfo();		// �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int accID;	// ���¹�ȣ
	int balance;	// �ܾ�
	char* cusName; // �� �̸�

public:
	Account(int ID, int money, char* name) : accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int getAccId() { return accID; }

	void Deposit(int money) {
		balance += money;
	}

	int WithDraw(int money) { //��ݾ� ��ȯ, ���� �� 0 ��ȯ
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;
	}

	void showAccInfo() {
		cout << "���� ID: " << accID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� ��: " << balance << endl;

	}
	~Account() {
		delete[]cusName;
	}

};
Account* accArr[100];
int accNum = 0;

void main() {
	int choice;

	while (1) {
		ShowMenu();
		cout << "���� : "; cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return;
		default:
			cout << "illegal selection . . . " << endl;
		}
	}
}

void ShowMenu() {
	cout << "------Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout << "[���°���]"<<endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney() {
	int money;
	int id;
	
	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccId() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}

void WithDrawMoney() {
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccId() == id) {
			if (accArr[i]->WithDraw(money) == 0) {
				cout << "�ܾ׺���" << endl;
				return;
			}
			cout << "��ݿϷ�" << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}