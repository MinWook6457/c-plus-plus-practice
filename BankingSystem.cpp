
#include <iostream>
#include <cstring>

#pragma warning(disable:4996)
using namespace std;

const int NAME_LEN = 20;

void ShowMenu();			// 메뉴출력
void MakeAccount();		// 계좌개설을 위한 함수
void DepositMoney();		// 입	금
void WithDrawMoney();		// 출	금
void ShowAllAccInfo();		// 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int accID;	// 계좌번호
	int balance;	// 잔액
	char* cusName; // 고객 이름

public:
	Account(int ID, int money, char* name) : accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int getAccId() { return accID; }

	void Deposit(int money) {
		balance += money;
	}

	int WithDraw(int money) { //출금액 반환, 부족 시 0 반환
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;
	}

	void showAccInfo() {
		cout << "계좌 ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl;

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
		cout << "선택 : "; cin >> choice;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout << "[계좌개설]"<<endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney() {
	int money;
	int id;
	
	cout << "[입   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccId() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID입니다." << endl;
}

void WithDrawMoney() {
	int money;
	int id;

	cout << "[출   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getAccId() == id) {
			if (accArr[i]->WithDraw(money) == 0) {
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID입니다." << endl;
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}