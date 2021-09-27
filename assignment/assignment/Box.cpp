#include<iostream>
#include<string>

#include "Box.h"

using namespace std;


Box::Box(double h, double l, double w, bool e) {
	height = h;		length = l;		width = w;		isEmpty = e;
}

void Box::print() {
	cout << "ºÎÇÇ´Â " << getVolume() << endl;
}



double Box::getVolume() {
	return height * length * width;
}

void Box::setHeight(double h) {
	height = h;
}
void Box::setLength(double l) {
	length = l;
}
void Box::setWidth(double w) {
	width = w;
}