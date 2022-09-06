#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW , INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

//계좌의 종류
enum { NORMAL = 1, CREDIT = 2};

/*
	클래스 이름 : Account
	클래스 유형 : Entity 클래스
	Entity 클래스	 특 징 : - 데이터적 성격이 강하다. 따라서 파일 및 데이터 베이스에 저장되는 데이터를 소유하고 있다.
						- 프로그램의 기능을 파악하는데 도움을 주지는 못한다.
						- 그러나 프로그램상에서 관리되는 데이터의 종류를 파악하는데 도움이 된다.
*/
class Account {
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name); // 오버로딩
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int WithDraw(int money);
	void ShowAccInfo() const;
};
Account::Account(int ID, int money, char* name) : accID(ID), balance(money) {
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::WithDraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return balance;
}

void Account::ShowAccInfo() const {
	cout << "계좌 ID : " << accID << endl;
	cout << "이 름 : " << cusName << endl;
	cout << "잔 액 : " << balance << endl;
}

class NormalAccount : public Account {
private:
	int interRate; // 이자율 % 단위
public:
	NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate) {
		//
	}

	virtual void Deposit(int money) {
		Account::Deposit(money); // 원금추가
		Account::Deposit(money * (interRate / 100.0)); // 이자추가
	} 
};

class HighCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special) : NormalAccount(ID,money,name,rate) , specialRate(special) {
		//
	}

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money); // 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0)); // 특별이자추가
	}
};

class AccountHandler {
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithDrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

void AccountHandler::ShowMenu() const {
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void AccountHandler::MakeAccount() {
	int sel;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌";
	cout << "2.신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> sel;
	
	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}
void AccountHandler::MakeNormalAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;
	cout << "신용등급(1toA,2toB,3toC)"; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	default:
		cout << "다시 입력하세요" << endl;
		break;
	}
}
void AccountHandler::DepositMoney() {
	int money;
	int id;

	cout << "[입   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}
void AccountHandler::WithDrawMoney() {
	int money;
	int id;

	cout << "[출   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
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

AccountHandler::AccountHandler() : accNum(0) {
	//
}

void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}

void main() {
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 :";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithDrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return;
		default:
			cout << "잘못된 선택입니다. . ." << endl;
		}
	}
}