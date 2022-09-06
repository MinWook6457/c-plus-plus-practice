#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
namespace COMPANY_POSITION {
	enum { CLERK,SENIOR,ASSIST,MANAGER };

	void showPositionInfo(int pos) {
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}
class NameCard {
private:
	char *name;
	char *company;
	char *phoneNumber;
	int position;

public:
	NameCard(const char* name, const char* company, const char* phoneNumber, int pos) : position(pos) {
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phoneNumber = new char[strlen(phoneNumber) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phoneNumber, phoneNumber);
	}
	NameCard(const NameCard & card) : position(card.position) {
		name = new char[strlen(card.name) + 1];
		company = new char[strlen(card.company) + 1];
		phoneNumber = new char[strlen(card.phoneNumber) + 1];

		strcpy(name, card.name);
		strcpy(company, card.company);
		strcpy(phoneNumber, card.phoneNumber);
	}
	void ShowNameInfo() {
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phoneNumber << endl;
		cout << "직급 : ";
		COMPANY_POSITION::showPositionInfo(position);
	}
	~NameCard() {
		delete []name;
		delete []company;
		delete []phoneNumber;
	}
};

void main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMPANY_POSITION::CLERK);
	NameCard copy1 = manClerk;

	NameCard manSeneior("Hong", "OrangeEng", "010-6666-8888", COMPANY_POSITION::SENIOR);
	NameCard copy2 = manSeneior;

	copy1.ShowNameInfo();
	copy2.ShowNameInfo();
}