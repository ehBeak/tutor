#include <iostream>
#include <string>
#define PI 3.141592

using namespace std;

class Shape
{
protected:
	int width;
	int height;
public:
	// 여기에 도형 클래스의 생성자와 멤버함수 정의

	Shape(int w, int h) {
		width = w; height = h;
	}
	
	virtual void print() {
		cout << "SHAPE" << endl;
		cout << "면적: " << height*width << endl;
	}
	
};

class TwoDimShape : public Shape
{
private:
	int area;
public:
	// 여기에 2차원도형 클래스의 생성자와 멤버함수들 정의

	TwoDimShape(int w, int h) : Shape(w, h) {
		area = w * h;
	}

	void print() {
		cout << "TwoDimShape" << endl;
		cout << "면적: " << area << endl;
	}
};

class ThreeDimShape : public Shape
{
private:
	int volume;
public:
	// 여기에 3차원도형 클래스의 생성자와 멤버함수들 정의

	ThreeDimShape(int w, int h, int l) : Shape(w, h) {
		volume = w * h * l;
	}

	void print() {
		cout << "ThreeDimShape" << endl;
		cout << "부피: " << volume << endl;
	}
};

class Rectangle : public TwoDimShape
{
	// 사각형 클래스에 추가 멤버변수 없음!
public:
	// 여기에 사각형 클래스의 생성자와 멤버함수 정의
	Rectangle(int w, int h) : TwoDimShape(w, h) {

	}
	double getArea()
	{
		return width * height;
	}

	void print() {
		cout << "Rectangle" << endl;
		cout << "면적: " << getArea() << endl;
	}

};

class Ellipse : public TwoDimShape
{
	// 타원 클래스에 추가 멤버변수 없음!
public:
	// 여기에 타원 클래스의 생성자와 멤버함수 정의

	Ellipse(int w, int h) : TwoDimShape(w, h){

	}


	double getArea()
	{
		return width * height * PI / 4;
	}

	void print() {
		cout << "Ellipse" << endl;
		cout << "부피: " << getArea() << endl;
	}

};

class Triangle : public TwoDimShape
{
	// 삼각형 클래스에 추가 멤버변수 없음!
public:
	// 여기에 삼각형 클래스의 생성자와 멤버함수 정의

	Triangle(int w, int h) : TwoDimShape(w, h) {

	}

	double getArea()
	{
		return width * height / 2;
	}

	void print() {
		cout << "Triangle" << endl;
		cout << "부피: " << getArea() << endl;
	}
};

class Sphere : public ThreeDimShape
{
private:
	int radius;
public:
	// 여기에 구 클래스의 생성자와 멤버함수 정의
	Sphere(int w, int h, int l) : ThreeDimShape(w, h, l) {
		radius = l;
	}

	double getVolume()
	{
		return ((double)3 / 4) * radius * radius * radius * PI;
	}

	void print() {
		cout << "Sphere" << endl;
		cout << "부피: " << getVolume() << endl;
	}
};

class Cube : public ThreeDimShape
{
private:
	int base;
public:
	// 여기에 육면체 클래스의 생성자와 멤버함수 정의

	Cube(int w, int h, int l) : ThreeDimShape(w, h, l) {
		base = l;
	}


	double getVolume()
	{
		return width * height * base;
	}

	void print() {
		cout << "Cube" << endl;
		cout << "부피: " << getVolume() << endl;
	}
};

class Cylinder : public ThreeDimShape
{
private:
	int radius;
public:
	// 여기에 원통 클래스의 생성자와 멤버함수 정의

	Cylinder(int w, int h, int l) : ThreeDimShape(w, h, l) {
		radius = l;
	}

	double getVolume()
	{
		return radius * radius * PI * height;
	}

	void print() {
		cout << "Cylinder" << endl;
		cout << "부피: " << getVolume() << endl;
	}
};

void printShape(Shape *s)
{
	s->print();
}

int main(void)
{
	// Ellipse(1,2), Rectangle(3,4), Triangle(5,6), 
	// Sphere(7,8,9), Cube(10,11,12), Cylinder(13,14,15)
	// 위와 같은 6개의 객체를 생성해서 up-casting해야 아래의 반복문을 사용할 수 있음
	TwoDimShape* arrayOfTwoDimShape[3];

	arrayOfTwoDimShape[0] = new Ellipse(1, 2);
	arrayOfTwoDimShape[1] = new Rectangle(3, 4);
	arrayOfTwoDimShape[2] = new Triangle(5, 6);


	ThreeDimShape* arrayOfThreeDimShape[3];

	arrayOfThreeDimShape[0] = new Sphere(7, 8, 9);
	arrayOfThreeDimShape[1] = new Cube(10, 11, 12);
	arrayOfThreeDimShape[2] = new Cylinder(13, 14, 15);


	for (int i = 0; i < 3; i++)
	{
		printShape(arrayOfTwoDimShape[i]);
		printShape(arrayOfThreeDimShape[i]);
	}

	return 0;
}