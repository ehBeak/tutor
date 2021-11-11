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
	os << d.year << "��" << d.month << "��" << d.day << "��" << endl;
	return os;
}
int main() {
	Date d1(2020, 12, 31);
	cout << d1;
	cout << "++ ������ : ";
	//++d1; // d1.operator++()
	cout << ++d1;

	cout << "�� �� �� ++ ������ : ";
	cout << ++d1;
	/*Date d2(2020, 12, 31);
	cout << d2;
	cout << "-- ������ : ";
	cout << --d2;
	cout << endl;*/

	/*Date d3(2021, 1, 1);
	cout << d3;
	cout << "++ ������ : ";
	cout << ++d3;*/
	/*Date d4(2021, 1, 1);
	cout << d4;
	cout << "-- ������ : ";
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
//	Employee e1("ȫ�浿", 100);
//	Employee e2("ȫ�漭", 110);
//
//	int salary = e1;
//	cout << "ȫ�浿�� salary = " << salary << endl;
//
//	cout << "ȫ�漭�� salary = " << e2 << endl;
//
//	if (e1 > e2)
//		cout << "ȫ�浿�� �޿��� ����" << endl;
//	else
//		cout << "ȫ�漭�� �޿��� ����" << endl;
//
//	return 0;
//}