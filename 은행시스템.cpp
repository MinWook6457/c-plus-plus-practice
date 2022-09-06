
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
const int NAME_LEN = 20;
typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LEN];
}Account;
Account accArr[100];
int accNum = 0;
void showMenu();
void makeAccount();
void depositMoney();
void WithdrawMoney();
void showAllAccInfo();
void main() {
	int choice;
	while (1) {
		showMenu();
		cout << "��  �� : "; cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			makeAccount();
			break;
		case 2:
			depositMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			showAllAccInfo();
			break;
		case 5:
			return;
		default:
			cout << "�߸��� ���� �Դϴ�." << endl;
			break;
		}
	}
}
void showMenu() {
	cout << "----Menu----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��	��" << endl;
	cout << "3. ��	��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� :"; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	strcpy(accArr[accNum].cusName, name);
	accArr[accNum].balance = balance;
	accNum++;
}

void depositMoney() {
	int money;
	int id;
	cout << "[��	 ��]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;
	if (money < 0) {
		cout << "�߸��� �ݾ� �Է��Դϴ�." << endl;
		return;
	}

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i].accID) {
			accArr[i].balance += money;
			cout << "�ԱݿϷ�!!" << endl << endl;
			return;
		}
	}
}

void WithdrawMoney() {
	int money;
	int id;
	cout << "[��	 ��]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i].accID) {
			if (accArr[i].balance < money) {
				cout << "�� �� �� ��" << endl;
				return;
			}
			else {
				accArr[i].balance -= money;
				cout << "��ݿϷ�!!" << endl << endl;
				return;
			}
		}
	}
	cout << "�������� ���� ID�Դϴ�!!" << endl;

}
void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "���� ID : " << accArr[i].accID << endl;
		cout << "��	�� : " << accArr[i].cusName << endl;
		cout << "��	�� : " << accArr[i].balance << endl;
	}
}