#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
	double vb1, vb2, vb3;
	Box b1(3.5, 4.4, 5.0, false), b2, b3;

	b3.setHeight(4.0);
	b3.setLength(5.0);
	b3.setWidth(2.4);

	cout << "========================================" << endl;
	cout << "박스 1 "; b1.print();
	cout << "박스 2 "; b2.print();
	cout << "박스 3 "; b3.print();
	cout << "========================================" << endl;
	vb1 = b1.getVolume();
	vb2 = b2.getVolume();
	vb3 = b3.getVolume();

	if (vb1 > vb2) {
		if (vb1 > vb3)
			cout << "박스1의 부피가 가장 큽니다 : " << vb1;
		else
			cout << "박스3의 부피가 가장 큽니다 : " << vb3;
	}
	else {
		if (vb2 > vb3)
			cout << "박스2의 부피가 가장 큽니다 : " << vb2;
		else
			cout << "박스3의 부피가 가장 큽니다 : " << vb3;
	}
	cout << endl;

	return 0;
}