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
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
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
	NameCard(const char* inputName, const char* inputCompany, const char* inputPhoneNumber, int pos) : position(pos) {
		name = new char[strlen(inputName) + 1];
		company = new char[strlen(inputCompany) + 1];
		phoneNumber = new char[strlen(inputPhoneNumber) + 1];

		strcpy(name, inputName);
		strcpy(company, inputCompany);
		strcpy(phoneNumber, inputPhoneNumber);
	}

	void ShowNameInfo() {
		cout << "�̸� : " << name << endl;
		cout << "ȸ�� : " << company << endl;
		cout << "��ȭ��ȣ : " << phoneNumber << endl;
		cout << "���� : ";
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
	manClerk.ShowNameInfo();

	NameCard manSeneior("Hong", "OrangeEng", "010-6666-8888", COMPANY_POSITION::SENIOR);
	manSeneior.ShowNameInfo();
}