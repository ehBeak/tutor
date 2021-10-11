#include <iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h = 0, int m = 0, int s = 0) :hour(h), minute(m), second(s) { }
	~Time() { }
	void setHour(int h) { hour = h; }
	void setMinute(int m) { minute = m; }
	void setSecond(int s) { second = s; }
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	void print() { cout << "시간은" << hour << ":" << minute << ":" << second << endl; }
};

// 여기에 전역함수 isEqual을 오버로딩하세요.
// 객체 비교를 위한 전역함수
bool isEqual(Time* obj1, Time* obj2) {
	if (obj1->getHour() != obj2->getHour()) {
		return false;
	}
	if (obj1->getMinute() != obj2->getMinute()) {
		return false;
	}
	if (obj1->getSecond() != obj2->getSecond()) {
		return false;
	}
	return true;
}

bool isEqual(Time& obj1, Time& obj2) {
	if (obj1.getHour() != obj2.getHour()) {
		return false;
	}
	if (obj1.getMinute() != obj2.getMinute()) {
		return false;
	}
	if (obj1.getSecond() != obj2.getSecond()) {
		return false;
	}
	return true;
}


void main()
{
	Time t1(10, 15, 20), t2;
	Time& tt1 = t1, & tt2 = t2;
	Time* pt1 = &t1, * pt2 = &t2;

	t2.setHour(10);
	t2.setMinute(15);
	t2.setSecond(20);

	cout << "t1 ";
	t1.print();
	cout << "t2 ";
	t2.print();

	cout << "t1과 t2의 시간은 같습니다. : " << isEqual(tt1, tt2) << endl;		//isEqual 함수의 리턴 타입은 bool
	cout << "t1과 t2의 시간은 같습니다. : " << isEqual(pt1, pt2) << endl;		//따라서, 참이면 1, 거짓이면 0이 출력됨
}