#include <iostream>
using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;

	Date() {
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	~Date() {}

	Date operator++() {

		Date d(0, 0, 0);

		d.day = this->day;
		d.month = this->month;
		d.year = this->year;

		if (d.day == 31) {
			if (d.month == 12) {
				d.day = 1; d.month = 1; d.year += 1;
			}
			else {
				d.day = 1; d.month += 1; //year = this->year;
			}
		}
		else {
			d.day += 1; //month = this->month; year = this->year;
		}

		return d;
	}
};
ostream& operator<<(ostream& os, const Date& d) {
	os << d.year << "년" << d.month << "월" << d.day << "일" << endl;
	return os;
}
int main() {
	Date d1(2020, 12, 31);
	cout << d1;
	cout << "++ 연산자 : ";
	//++d1; // d1.operator++()
	cout << ++d1;

	cout << "한 번 더 ++ 연산자 : ";
	cout << ++d1;
	/*Date d2(2020, 12, 31);
	cout << d2;
	cout << "-- 연산자 : ";
	cout << --d2;
	cout << endl;*/

	/*Date d3(2021, 1, 1);
	cout << d3;
	cout << "++ 연산자 : ";
	cout << ++d3;*/
	/*Date d4(2021, 1, 1);
	cout << d4;
	cout << "-- 연산자 : ";
	cout << --d4;*/
	return 0;
}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Employee {
//private:
//	string name;
//	int salary;
//public:
//	Employee() {
//		name = "Unknown";
//		salary = 0;
//	}
//	Employee(string name, int salary)
//	{
//		this->name = name;
//		this->salary = salary;
//	}
//
//	operator int() { return salary; }
//};
//
//int main()
//{
//	Employee e1("홍길동", 100);
//	Employee e2("홍길서", 110);
//
//	int salary = e1;
//	cout << "홍길동의 salary = " << salary << endl;
//
//	cout << "홍길서의 salary = " << e2 << endl;
//
//	if (e1 > e2)
//		cout << "홍길동의 급여가 높다" << endl;
//	else
//		cout << "홍길서의 급여가 높다" << endl;
//
//	return 0;
//}