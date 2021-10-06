#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;	// 책 제목
	int price;		// 책 가격


public:
	Book(const char* t, int p);
	~Book();
	void set(const char* t, int p);
	void show() { cout << title << ' ' << price << "원" << endl; }

	//깊은 복사 생성자
	Book(const Book& b);
};

// 생성자
Book::Book(const char* t, int p) {
	
	//1. 동적 메모리 할당
	title = new char[strlen(t) + 1];

	//2. 메모리에 복사
	strcpy(title, t);

	price = p;

}

Book::Book(const Book& b) {
	//1. 동적 메모리 할당
	title = new char[strlen(b.title) + 1];

	//2. 메모리에 복사
	strcpy(title, b.title);

	price = b.price;
}

// 소멸자
Book::~Book() { delete[] title; }

// set함수
void Book::set(const char* t, int p) {

	delete[] title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	price = p;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java(cpp);
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}