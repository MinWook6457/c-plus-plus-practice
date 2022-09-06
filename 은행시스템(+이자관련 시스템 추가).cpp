#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
const int NAME_LEN = 20;

// ���α׷� ������� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW , INQUIRE, EXIT};

// �ſ���
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

//������ ����
enum { NORMAL = 1, CREDIT = 2};

/*
	Ŭ���� �̸� : Account
	Ŭ���� ���� : Entity Ŭ����
	Entity Ŭ����	 Ư ¡ : - �������� ������ ���ϴ�. ���� ���� �� ������ ���̽��� ����Ǵ� �����͸� �����ϰ� �ִ�.
						- ���α׷��� ����� �ľ��ϴµ� ������ ������ ���Ѵ�.
						- �׷��� ���α׷��󿡼� �����Ǵ� �������� ������ �ľ��ϴµ� ������ �ȴ�.
*/
class Account {
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name); // �����ε�
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
	cout << "���� ID : " << accID << endl;
	cout << "�� �� : " << cusName << endl;
	cout << "�� �� : " << balance << endl;
}

class NormalAccount : public Account {
private:
	int interRate; // ������ % ����
public:
	NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate) {
		//
	}

	virtual void Deposit(int money) {
		Account::Deposit(money); // �����߰�
		Account::Deposit(money * (interRate / 100.0)); // �����߰�
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
		NormalAccount::Deposit(money); // ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0)); // Ư�������߰�
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void AccountHandler::MakeAccount() {
	int sel;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���";
	cout << "2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;
	cout << "�ſ���(1toA,2toB,3toC)"; cin >> creditLevel;
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
		cout << "�ٽ� �Է��ϼ���" << endl;
		break;
	}
}
void AccountHandler::DepositMoney() {
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}
void AccountHandler::WithDrawMoney() {
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
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
		cout << "���� :";
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
			cout << "�߸��� �����Դϴ�. . ." << endl;
		}
	}
}