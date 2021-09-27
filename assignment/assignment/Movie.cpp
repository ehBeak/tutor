#include<iostream>
#include<string>

#include "Movie.h"

Movie::Movie() {}

Movie::Movie(string n, string d, double p) {
	name = n;	dirctor = d;	point = p;
}

void Movie::setName(string n) {
	name = n;
}
void Movie::setDirector(string d) {
	dirctor = d;
}
void Movie::setPoint(double p) {
	point = p;
}

void Movie::print() {
	cout << "영화제목 : " << getName() << endl;
	cout << "감    독 : " << getDirector() << endl;
	cout << "평    점 : " << getPoint() << endl;

}

double Movie::getPoint() {
	return point;
}

string Movie::getName() {
	return name;
}

string Movie::getDirector() {
	return dirctor;
}