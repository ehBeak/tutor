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
	// ���⿡ ���� Ŭ������ �����ڿ� ����Լ� ����

	Shape(int w, int h) {
		width = w; height = h;
	}
	
	virtual void print() {
		cout << "SHAPE" << endl;
		cout << "����: " << height*width << endl;
	}
	
};

class TwoDimShape : public Shape
{
private:
	int area;
public:
	// ���⿡ 2�������� Ŭ������ �����ڿ� ����Լ��� ����

	TwoDimShape(int w, int h) : Shape(w, h) {
		area = w * h;
	}

	void print() {
		cout << "TwoDimShape" << endl;
		cout << "����: " << area << endl;
	}
};

class ThreeDimShape : public Shape
{
private:
	int volume;
public:
	// ���⿡ 3�������� Ŭ������ �����ڿ� ����Լ��� ����

	ThreeDimShape(int w, int h, int l) : Shape(w, h) {
		volume = w * h * l;
	}

	void print() {
		cout << "ThreeDimShape" << endl;
		cout << "����: " << volume << endl;
	}
};

class Rectangle : public TwoDimShape
{
	// �簢�� Ŭ������ �߰� ������� ����!
public:
	// ���⿡ �簢�� Ŭ������ �����ڿ� ����Լ� ����
	Rectangle(int w, int h) : TwoDimShape(w, h) {

	}
	double getArea()
	{
		return width * height;
	}

	void print() {
		cout << "Rectangle" << endl;
		cout << "����: " << getArea() << endl;
	}

};

class Ellipse : public TwoDimShape
{
	// Ÿ�� Ŭ������ �߰� ������� ����!
public:
	// ���⿡ Ÿ�� Ŭ������ �����ڿ� ����Լ� ����

	Ellipse(int w, int h) : TwoDimShape(w, h){

	}


	double getArea()
	{
		return width * height * PI / 4;
	}

	void print() {
		cout << "Ellipse" << endl;
		cout << "����: " << getArea() << endl;
	}

};

class Triangle : public TwoDimShape
{
	// �ﰢ�� Ŭ������ �߰� ������� ����!
public:
	// ���⿡ �ﰢ�� Ŭ������ �����ڿ� ����Լ� ����

	Triangle(int w, int h) : TwoDimShape(w, h) {

	}

	double getArea()
	{
		return width * height / 2;
	}

	void print() {
		cout << "Triangle" << endl;
		cout << "����: " << getArea() << endl;
	}
};

class Sphere : public ThreeDimShape
{
private:
	int radius;
public:
	// ���⿡ �� Ŭ������ �����ڿ� ����Լ� ����
	Sphere(int w, int h, int l) : ThreeDimShape(w, h, l) {
		radius = l;
	}

	double getVolume()
	{
		return ((double)3 / 4) * radius * radius * radius * PI;
	}

	void print() {
		cout << "Sphere" << endl;
		cout << "����: " << getVolume() << endl;
	}
};

class Cube : public ThreeDimShape
{
private:
	int base;
public:
	// ���⿡ ����ü Ŭ������ �����ڿ� ����Լ� ����

	Cube(int w, int h, int l) : ThreeDimShape(w, h, l) {
		base = l;
	}


	double getVolume()
	{
		return width * height * base;
	}

	void print() {
		cout << "Cube" << endl;
		cout << "����: " << getVolume() << endl;
	}
};

class Cylinder : public ThreeDimShape
{
private:
	int radius;
public:
	// ���⿡ ���� Ŭ������ �����ڿ� ����Լ� ����

	Cylinder(int w, int h, int l) : ThreeDimShape(w, h, l) {
		radius = l;
	}

	double getVolume()
	{
		return radius * radius * PI * height;
	}

	void print() {
		cout << "Cylinder" << endl;
		cout << "����: " << getVolume() << endl;
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
	// ���� ���� 6���� ��ü�� �����ؼ� up-casting�ؾ� �Ʒ��� �ݺ����� ����� �� ����
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