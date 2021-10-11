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
	void print() { cout << "�ð���" << hour << ":" << minute << ":" << second << endl; }
};

// ���⿡ �����Լ� isEqual�� �����ε��ϼ���.
// ��ü �񱳸� ���� �����Լ�
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

	cout << "t1�� t2�� �ð��� �����ϴ�. : " << isEqual(tt1, tt2) << endl;		//isEqual �Լ��� ���� Ÿ���� bool
	cout << "t1�� t2�� �ð��� �����ϴ�. : " << isEqual(pt1, pt2) << endl;		//����, ���̸� 1, �����̸� 0�� ��µ�
}