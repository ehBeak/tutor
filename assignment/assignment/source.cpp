#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;

int main()
{
	double p1, p2, p3;
	Movie m1("후쿠오카", "장률", 7.71), m2("카일라스 가는 길", "정형민", 9.72), m3;

	m3.setName("이별식당");
	m3.setDirector("임왕태");
	m3.setPoint(8.06);

	cout << "========================================" << endl;
	m1.print();
	m2.print();
	m3.print();
	cout << "========================================" << endl;
	p1 = m1.getPoint();
	p2 = m2.getPoint();
	p3 = m3.getPoint();

	if (p1 > p2) {
		if (p1 > p3)
			cout << "가장 평점이 좋은 영화 : " << m1.getName() << endl;
		else
			cout << "가장 평점이 좋은 영화 : " << m3.getName() << endl;
	}
	else {
		if (p2 > p3)
			cout << "가장 평점이 좋은 영화 : " << m2.getName() << endl;
		else
			cout << "가장 평점이 좋은 영화 : " << m3.getName() << endl;
	}

	cout << endl;

	return 0;
}