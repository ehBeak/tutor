#pragma once

#include<string>

using namespace std;

class Movie {
	string name;
	string dirctor;
	double point;

public:
	Movie();
	Movie(string n, string d, double p);

	void setName(string n);
	void setDirector(string d);
	void setPoint(double p);

	void print();

	double getPoint();

	string getName();

	string getDirector();
};
