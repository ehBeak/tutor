#pragma once

class Box {

	double height;
	double length;
	double width;

	bool isEmpty;

public:
	Box(double h = 5.0, double l = 6.0, double w = 7.0, bool e = true);

	void print();

	double getVolume();

	void setHeight(double h);
	void setLength(double l);
	void setWidth(double w);

	

};
