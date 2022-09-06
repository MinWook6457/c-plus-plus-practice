
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Girl; // 정의가 뒤에 나오는 함수 호출을 위해서 원형 선언

class Boy {
private:
	int height;
	friend class Girl; // friend 선언은 private이나 public이나 상관없음
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