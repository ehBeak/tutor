#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;	// å ����
	int price;		// å ����


public:
	Book(const char* t, int p);
	~Book();
	void set(const char* t, int p);
	void show() { cout << title << ' ' << price << "��" << endl; }

	//���� ���� ������
	Book(const Book& b);
};

// ������
Book::Book(const char* t, int p) {
	
	//1. ���� �޸� �Ҵ�
	title = new char[strlen(t) + 1];

	//2. �޸𸮿� ����
	strcpy(title, t);

	price = p;

}

Book::Book(const Book& b) {
	//1. ���� �޸� �Ҵ�
	title = new char[strlen(b.title) + 1];

	//2. �޸𸮿� ����
	strcpy(title, b.title);

	price = b.price;
}

// �Ҹ���
Book::~Book() { delete[] title; }

// set�Լ�
void Book::set(const char* t, int p) {

	delete[] title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	price = p;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java(cpp);
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}