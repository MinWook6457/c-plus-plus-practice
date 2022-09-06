
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Girl; // ���ǰ� �ڿ� ������ �Լ� ȣ���� ���ؼ� ���� ����

class Boy {
private:
	int height;
	friend class Girl; // friend ������ private�̳� public�̳� �������
public:
	Boy(int len) : height(len) {

	}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl {
private:
	char phNum[20];
public:
	Girl(const char* num) {
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};
void Boy::ShowYourFriendInfo(Girl& frn) {
	cout << "Her Phone Number : " << frn.phNum << endl;
}
void Girl::ShowYourFriendInfo(Boy& frn) {
	cout << "His Height : " << frn.height << endl;
}
void main() {
	Boy boy(170);
	Girl girl("010-9999-8888");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
}