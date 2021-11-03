#include <iostream>
using namespace std;

class Complex
{
	// 필요한 멤버 구성
public:
	friend Complex add(Complex, Complex);
	Complex(double r, double i) { re = r; im = i; }
	Complex(double r) { re = r; im = i; }
	Complex() { re = im = 0; }
	void Ouput() {
		cout << re << " + " << im << "i" << endl;
	}

	ostream& operator<<(ostream& os) {
		os << this->re << " + " << this->im << "i" << endl;
		return os;
	}
private:
	double re, im;
};

// 필요한 전역 함수 정의
Complex add(Complex a1, Complex a2) {
	return Complex(a1.re + a2.re, a1.im + a2.im);
}



int main()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3 = c1 + c2;

	c1 << cout;

	cout << c3 << endl;

	c3 = c3 + 1;
	cout << c3 << endl;

	cout << "c1, c2, c3 : " << endl;
	c3 << (c2 << (c1 << cout));
	cout << endl;

	cout << "c1, c2, c3 : " << endl;
	cout << c1 << c2 << c3 << endl; // Ostream& operator+(Ostream& c1, Complex& c2)
	// cout.operator+(c1)
	return(0);
}
