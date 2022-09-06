
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
		cout << "선  택 : "; cin >> choice;
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
			cout << "잘못된 선택 입니다." << endl;
			break;
		}
	}
}
void showMenu() {
	cout << "----Menu----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입	금" << endl;
	cout << "3. 출	금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 :"; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	strcpy(accArr[accNum].cusName, name);
	accArr[accNum].balance = balance;
	accNum++;
}

void depositMoney() {
	int money;
	int id;
	cout << "[입	 금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;
	if (money < 0) {
		cout << "잘못된 금액 입력입니다." << endl;
		return;
	}

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i].accID) {
			accArr[i].balance += money;
			cout << "입금완료!!" << endl << endl;
			return;
		}
	}
}

void WithdrawMoney() {
	int money;
	int id;
	cout << "[출	 금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i].accID) {
			if (accArr[i].balance < money) {
				cout << "잔 액 부 족" << endl;
				return;
			}
			else {
				accArr[i].balance -= money;
				cout << "출금완료!!" << endl << endl;
				return;
			}
		}
	}
	cout << "유요하지 않은 ID입니다!!" << endl;

}
void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌 ID : " << accArr[i].accID << endl;
		cout << "이	름 : " << accArr[i].cusName << endl;
		cout << "잔	액 : " << accArr[i].balance << endl;
	}
}