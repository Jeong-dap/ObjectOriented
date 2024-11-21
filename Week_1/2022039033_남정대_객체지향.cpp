#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;
int sum(int a, int b);
int ex0909() {
	int n;
	cout << "������ �Է��ϼ��� >> ";
	cin >> n;
	if (n <= 0) {
		cout << " ����� �Է��ϼ���!\n";
		return 0;
	}
	cout << "1���� "<< n << "������ ����" << sum(1, n) << "�Դϴ�.\n";
	return 0;
}
int sum(int a, int b) {
	int res = 0;
	for (int k = a; k <= b; k++) {
		res += k;
	}
	return res;
}

double biggest(double* a, int N) {
	double a_max = a[0];
	for (int i = 0; i < N; i++) {
		if (a[i] > a_max) {
			a_max = a[i];
		}
	}
	return a_max;
}

void ex0912_2() {

	int N = 7;
	double a[7];
	cout << "7 ���� �Ǽ��� �Է��϶� >> ";
	for (int n = 0; n < N; n++) {
		cin >> a[n];
	}

	double a_max = biggest(a, N);
	cout << a_max << endl;
}

void ex0912_3() {
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	int* q[2];
	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl;

	//////////////////////////////////// ���� �ڵ� /////////////////////////////////////////
	int* p = K;
	cout << p[0] << " " << p[1] << " " << p[2] << endl;
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl;
	
	p = &K[2];
	cout << *p << " " << *(p - 2) << endl;
	cout << p[0] << " " << p[-2] << endl;
}

void ex0912_4() {
	int K[3] = { 7, 8, 9 };
	int M[4] = { 6, 5, 4, 0 };
	int N[2] = { 1, 2 };

	int* p;
	int* q[3];	// <--- q[0], q[1], q[3]

	q[0] = K;
	q[1] = M;
	q[2] = N;

	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl;
	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl;

	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << " " << *(q[1] + 3) << endl;
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << " " << q[1][3] << endl;

	cout << *(q[2] + 0) << " " << *(q[2] + 1) << endl;
	cout << q[2][0] << " " << q[2][1] << endl;
	cout << *(*(q + 2) + 0) << " " << *(*(q + 2) + 1) << endl;
}
//////////////////////////////////////������///////////////////////////////////////
void pfunc_1_(int* a, int* b) {			// �ּҰ��� �����ϴ� *a, *b�� ����
	cout << *a << " " << *b << endl;
	*a = 30, * b = 40;					// �׳� a�� �׳� b�� �ּҰ��̹Ƿ� *a�� 30 ����, *b �� 40 ����
}
//////////////////////////////////// ���۷���///////////////////////////////////////
void pfunc_2_(int& c, int& d) {			// �ּҶ�� �ǹ̰� �ƾƴϰ� ���۷��� ��ȣ
	cout << c << " " << d << endl;
	c = 30, d = 40;
}
void ex0919_2() {
	int a = 10, b = 20;
	pfunc_1_(&a, &b);	// �ּҸ� ����
	cout << a << " " << b << endl;
}

void ex0919_3() {
	int a = 10, b = 20;
	pfunc_2_(a, b);
	cout << a << " " << b << endl;
}

void ex0919_4() {
	int a = 1;
	int b[5] = { 10, 20, 30, 40, 50 };
	int& c = a;
	cout << c << endl;
	c = b[3];
	cout << c << endl;
}

bool average(int a[], int size, float& avg) {
	avg = 0.0;
	for (int i = 0; i < size; i++) {
		avg += a[i];
	}
	avg /= size;
	return true;
}

void ex0919_5() {
	int x[] = { 0, 1, 2, 3, 4, 5 };
	float avg;
	average(x, 6, avg);
	cout << "����� " << avg << endl;
}

bool bigger(int a, int b, int& big) {
	if (a > b) { 
		big = a;
		return false;
	}
	else if (a < b) {
		big = b;
		return false;
	}
	else { return true; }
}
/*
bool bigger(int x, int y, int& big) {
	bool b;
	if (xx == yy) {
		b = true;
	}
	else if (xx != yy) {
		b = false;
		big = (xx > yy) ? xx : yy;	// #define imax(xx, yy) ((xx > yy) ? xx : yy);
		}
	}
}
*/


void ex0923_1() {
	int x, y, big;
	bool b;
	cout << "�� ������ �Է��ϼ��� >> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b) { cout << "same" << endl; }
	else { cout << "ū ���� " << big << endl; }
}

int sum3(int a, int b = 200, int c = 100) {		// default ���ڸ� �ٶ��� �����ʺ��� ���� & �����Ѵ�.
	return a + b + c;
}

void ex0923_2() {
	int x = 10, y = 20, z = 30;
	int w = sum3(x, y, z);
	int u = sum3(x, y);
	int v = sum3(x);
	cout << w << " " << u << " " << v << endl;
}

void f(char c = ' ', int line = 1) {
	for (int j = 0; j < line; j++) {
		for (int i = 0; i < 10; i++) {
			cout << c;
		}
		cout << endl;
	}
}

void ex0923_3() {
	f();
	f('%');
	f('@', 5);
}

int ssum(int a, int b, int c) {
	return a + b + c;
}

double ssum(double a, double b, double c) {
	return a + b + c;
}

int ssum(int a, int b) {
	return a + b;
}

void ex0923_4() {
	cout << ssum(2, 5, 33) << endl;
	cout << ssum(2.5, 100.6, 10.7) << endl;
	cout << ssum(2, 6) << endl;
}

int big(int a, int b) {
	int max_value = (a > b) ? a : b;
	if (max_value <= 100) {	return max_value;}
	else { return 100; }
}

int big(int a, int b, int c) {
	int max_value = (a > b) ? a : b;
	if (max_value <= c) { return max_value; }
	else { return c; }
}

void ex0923_5() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << " " << y << " " << z << endl;
}

void myswap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void myswap(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void ex0923_6() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) ȣ��
	cout << a << '\t' << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) ȣ��
	cout << c << '\t' << d << endl;
}

template <class T> void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//int add(int* x, int num) {
//	int sum = 0;
//	for (int i = 0; i < num; i++) {
//		sum += x[i];
//	}
//	return sum;
//}
//
//double add(double* x, double num) {
//	double sum = 0;
//	for (int i = 0; i < num; i++) {
//		sum += x[i];
//	}
//	return sum;
//}

template <class T1, class T2> T1 add(T1* x, T2 num) {
	T1 sum = 0;
	for (int i = 0; i < num; i++) {
		sum += x[i];
	}
	return sum;
}

void ex0926_1() {
	int x[] = { 1, 2, 3, 4, 5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	float y[] = { 1, 2, 3, 4, 5, 6 };

	cout << "sum of x[] = " << add(x, 5) << endl;
	cout << "sum of d[] = " << add(d, 6) << endl;
	cout << "sum of y[] = " << add(y, 6) << endl;
}

class Circle {
private:			///////////////////////// private�� public���� �ƹ��͵� ���� ������ private���� �� //////////
	
public:
	int radius;
	double getArea() {
		double area = 3.14 * radius * radius;		// class�� radius�� ����Ǿ� �����Ƿ� �׳� ��� ����
		return area;
	}
};

//double Circle::getArea() {
//	double area = 3.14 * radius * radius;		// class�� radius�� ����Ǿ� �����Ƿ� �׳� ��� ����
//	return area;
//}

void ex0926_2() {
	Circle A, B, C;
	A.radius = 10;
	cout << A.getArea() << endl;

	Circle* p = &A;
	cout << (*p).radius << endl;
	cout << p->radius << endl;
	cout << p->getArea() << endl;
}

class Rectangle {
public :
	int width;
	int height;
	int getArea() {
		int area = width * height;
		return area;
	}
};

void ex0926_3() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;
}

class Rectangle2 {
private:
	int width;
	int height;
public:
	int getArea() {
		int area = width * height;
		return area;
	}
	bool setWidth(int input) {
		if (input < 0) { return false; }
		else {
			width = input;
			return true;
		}		
	}
	bool setHeight(int input) {	
		if (input < 0) { return false; }
		else {
			height = input;
			return true;
		}
	}
	int getWidth() { return width; }
	int getHeight() { return height; }
};

void ex0926_4() {
	Rectangle2 rect;
	if (rect.setWidth(3) == false) {
		cout << "width error" << endl;
		return;
	}
	if (rect.setHeight(5) == false) {
		cout << "height error" << endl;
		return;
	}

	cout << "width = " << rect.getWidth() << endl;
	cout << "Height = " << rect.getHeight() << endl;
	cout << "�簢���� ������ " << rect.getArea() << endl;
}

class Circle2 {
public:
	int radius;
	Circle2();
	Circle2(int r);
	~Circle2();			// �Ҹ��� ==> �Ҹ��� ������ �������� �۵�
	double getArea();	// ����Լ� == *�޼ҵ�(method)
};

Circle2::~Circle2() {			// �Ҹ���
	cout << "������ " << radius << " �� �Ҹ�" << endl;
}

Circle2::Circle2() {			// �⺻ ������
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle2::Circle2(int r) {		// �Ű������� �޴� ������
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

double Circle2::getArea() {		// ���� ���̸� ��ȯ�ϴ� �Լ�
	return 3.14 * radius * radius;
}

void ex0930_1() {
	Circle2 donut;
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	Circle2 pizza(30);
	area = pizza.getArea();
	cout << "pizza ������" << area << endl;
}
void func0930();

void ex0930_2() {
	func0930();
	Circle2 pizza(30);	// (2)
	double area = pizza.getArea();
	cout << "pizza ������" << area << endl;

}
void func0930() {
	Circle2 donut;	// (1)
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;
}

class Rectangle3 {
public:
	int width, height;
	Rectangle3() { width = 1; height = 1; }
	Rectangle3(int width_in, int height_in) {
		width = width_in;		// this->width = width;
		height = height_in;
	}
	Rectangle3(int length) {
		width = height = length;
	}
	~Rectangle3() {
		cout << "�Ҹ�" << width << " " << height << endl;
	}
	bool isSquare();
};

bool Rectangle3::isSquare() {
	if (width == height) { return true; }
	else { return false; }
}

void ex0930_3() {
	Rectangle3 rect1;
	Rectangle3 rect2(3, 5);
	Rectangle3 rect3(3);

	if (rect1.isSquare()) { cout << "rect1�� ���簢���̴�." << endl; }
	if (rect2.isSquare()) { cout << "rect2�� ���簢���̴�." << endl; }
	if (rect3.isSquare()) { cout << "rect3�� ���簢���̴�." << endl; }
}

class Oval {
public:
	int width, height;
	Oval() { width = 1, height = 1; }
	Oval(int w, int h) { width = w; height = h; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	double getArea();
	void set(int w, int h) { width = w; height = h; }
	void show() { cout << "width = " << width << ", height = " << height << endl; }
	~Oval() { cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl; }
};
double Oval::getArea() { return 3.14 * width * height; }


void ex0930_4() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}

inline bool isEven(int B) {
	if (B % 2 == 0) { return true; }
	else { return false; }
}

void ex0930_5() {
	int A = 345;
	if (isEven(A)) { cout << A << "��(��) ¦����!"; }	// if (isEven(A) == true)�� ���� ����
	else { cout << A << "��(��) Ȧ����!"; }
}

//#include "cal.h"

class Cal {
public:
	void run();
};

//void Cal::run() {
//	cout << "�� ���� ���� �Է��ϼ��� >> ";
//	int a, b;
//	cin >> a >> b;
//	Adder adder(a, b);
//	cout << adder.process();
//}
//
//void ex1007_1() {
//	Cal clac;
//	clac.run();
//}

class Ram {
	char mem[100 * 1024]; // 100KB �޸�
	int size;
public:
	Ram(); // mem�� 0���� �ʱ�ȭ�ϰ� size�� 100*1024�� �ʱ�ȭ	// ������
	~Ram(); // "�޸� ���ŵ�" ���ڿ� ���		// �Ҹ���
	char read(int address); // address �ּ��� �޸𸮸� �о� ����
	void write(int address, char value); // address �ּҿ� value ����
	// �ּҰ� ������ ����� ���� �߻��ϸ� �����޽��� �����.
};

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}

Ram::~Ram() { cout << "�޸� ���ŵ�" << endl; }

char Ram::read(int address) { return mem[address]; }

void Ram::write(int address, char value) { mem[address] = value; }

void ex1007_2() {
	Ram ram;
	ram.write(100, 20); // 100 ������ 20 ����
	ram.write(101, 30); // 101 ������ 30 ����
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 ������ 50 ����
	cout << "102 ������ �� = " << (int)ram.read(102) << endl; // 102 ���� �޸� �� ���
}

// static : ����
// dynamic : ����

//class Person {
//public:
//	double money; // ���� ������ ��
//	void addMoney(int money) {
//		this->money += money;
//	}
//	Person() { money = 0; }
//	static int sharedMoney; // ����
//	static void addShared(int n) {
//		sharedMoney += n;
//	}
//};
//// static ���� ����. ���� ������ ����
//int Person::sharedMoney = 10; // 10���� �ʱ�ȭ

//void ex1007_3() {
//	Person han;
//	han.money = 100; // han�� ���� ��=100
//	han.sharedMoney = 200; // static ��� ����, ����=200
//
//	Person lee;
//	lee.money = 150; // lee�� ���� ��=150
//	lee.addMoney(200); // lee�� ���� ��=350
//	lee.addShared(200); // static ��� ����, ����=400
//	cout << han.money << ' ' << lee.money << endl;
//	cout << han.sharedMoney << ' ' << lee.sharedMoney << ' ' << Person::sharedMoney << endl;
//}

class Math {
public:
	static int abs(int a) { return a > 0 ? a : a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (b > a) ? b : a; }
};

void ex1010_1() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;

	Math m;
	cout << m.abs(-5) << endl;
	cout << m.max(10, 8) << endl;
	cout << m.min(-3, -8) << endl;
}

class Person2 {
public:
	int money;
	string name;
	static int sharedMoney;
	Person2() { money = 0; }
	Person2(string name_in) {
		money = 0;
		name = name_in;
	}
	void addMoney(int money_in) {
		money += money_in;
	}
	static void addShared(int sharedmoney_in) {		// static ��� ������ �ޱ� ������ static ��� �Լ��� ����
		sharedMoney += sharedmoney_in;
	}
	~Person2() {
		cout << name << "'s money = " << money << endl;
	}
};

int Person2::sharedMoney = 0;		// static ������ class ������ �ʱ�ȭ �� �� �����Ƿ� class �ۿ��� �ʱ�ȭ

void ex1010_2() {
	Person2 A("KANG"), B("KIM");
	// 3��
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	// 4��
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "���� = " << Person2::sharedMoney << endl;
	Person2::addShared(100);
	cout << "���� = " << Person2::sharedMoney << endl;
}

void ex1010_3() {
	Person2 A("KANG"), B("KIM");
	// 3��
	A.addMoney(100);
	A.addShared(5);

	Person2* p = &A;

	cout << A.money << ' ' << (*p).money << ' ' << p->money << endl;
//p : �ּ�
//&A : ��ü
//A : ��ü
//*p : ��ü(p�� ����Ű�� �ִ� ��ü)
}

void ex1010_4() {
	Circle circleArray[3];
//	Circle circleArray[0] Circle circleArray[1] Circle circleArray[2]
	circleArray[0].radius = 100;
	circleArray[1].radius = 50;
	circleArray[2].radius = 70;
	
	Circle* p = &circleArray[1];
	cout << (*p).radius << ' ' << p->radius << endl;

	Circle2 carray[3] = {Circle2(20), Circle2(10), Circle2()};
	Circle2* q;
	q = carray;
	cout << carray[0].radius << ' ' << q[0].radius << endl;

	q = &carray[1];
	cout << q[-1].radius << ' ' << q[0].radius << ' ' << (q + 1)->radius << endl;
}

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

void ex1014_1() {
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();	// (*p).show(); �̰Ͱ� ����.
	Color colors[3];
	p = colors;

	p->setColor(255, 0, 0);			// colors[0].setColor(255, 0, 0);	p[0].setColor(255, 0, 0);	�� �� ��� ����
	(p + 1)->setColor(0, 255, 0);	// colors[1].setColor(0, 255, 0);	p[1].setColor(0, 255, 0);	
	(p + 2)->setColor(0, 0, 255);	// colors[2].setColor(0, 0, 255);	p[2].setColor(0, 0, 255);	

	for (int i = 0; i < 3; i++) {
		(p + i)->show();
	}
}

void ex1014_2() {
	int A[5];
	A[0] = 100; A[1] = 200; A[2] = 300; A[3] = 400; A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d\n", A[i]);
	}
}

void ex1014_3(int number) {
	int* A = (int*)malloc(number * sizeof(int));		// �޸� �Ҵ�
	A[0] = 100; A[1] = 200; A[2] = 300; A[3] = 400; A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d %d", A[i], *(A + i));
	}
	free(A);	// �޸� �Ҵ� ����
}

void ex1014_4(int number) {
	int* A = new int[number];	/*(int*)malloc(5 * sizeof(int));*/		// �޸� �Ҵ�
	A[0] = 100; A[1] = 200; A[2] = 300; A[3] = 400; A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d %d", A[i], *(A + i));
	}
	delete[] A;	// new ���� �޸� �Ҵ� ����
	//free(A); malloc ���� �޸� �Ҵ� ����
}

void ex1014_5() {
	Circle2* p, * q;
	p = new Circle2;
	q = new Circle2(10);

	cout << p->getArea() << endl;	// (*p).getArea()�� ����
	cout << q->getArea() << endl;	// (*q).getArea()�� ����

	delete p;
	delete q;
}

void ex1014_6() {
	Circle2* p = new Circle2[3];

	cout << p[0].getArea() << endl;
	cout << p[1].getArea() << endl;
	cout << p[2].getArea() << endl;

	Circle2* q = p;

	cout << (*(q + 0)).getArea() << endl;
	cout << (*(q + 1)).getArea() << endl;
	cout << (*(q + 2)).getArea() << endl;

	delete[] p;
}

class PERSON {
	string name;
public:
	PERSON() { name = ""; }
	PERSON(string name_in) { name = name_in; }
	string getName() { return name; }
	void setName(string name_in) { this->name = name_in; }
};

class Family {
	string name;
	PERSON* p;
	int size;
public:
	Family(string name_in, int size_in);
	void setName(int index, string name_in);
	void show();
	~Family();
};

Family::Family(string name_in, int size_in) {
	name = name_in;
	size = size_in;
	p = new PERSON[size];
}

void Family::setName(int index, string name_in) {
	(p + index)->PERSON::setName(name_in);
}

void Family::show() {
	cout << name << " ������ ������ ���� " << size << "�� �Դϴ�." << endl;
	for (int i = 0; i < size; i++) {
		cout << (p + i)->getName() << " ";
	}
}

Family::~Family() { delete[] p; }

void ex1017_1() {
	Family* simpson = new Family("simpson", 4);
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->setName(3, "Baby Simpson");
	simpson->show();
}

class A {
public:
	int value;
};

class B {
public:
	int counter;
	A sub;
};

void ex1017_2() {
	int abc = 100;
	int* p = new int(200);
	cout << *p << endl;
	delete p;
}
//////////////// �⸻��� ///////////////
class Circle3 {
private:
	int radius;
public:
	Circle3();
	Circle3(int r);
	~Circle3();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};
Circle3::Circle3() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}
Circle3::Circle3(int radius) {
	this->radius = radius;
	cout << "������ ���� radius = " << radius << endl;
}
Circle3::~Circle3() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

void increase(Circle3 c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void increase(Circle3* p) {
	int r = p->getRadius();		// (*p).getRadius();
	p->setRadius(r + 1);		// (*p).setRadius(r + 1);
}

void increaseREF(Circle3& c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void ex1028_1() {
	Circle3 waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}

void ex1028_2() {
	Circle3 waffle(30);
	increase(&waffle);
	cout << waffle.getRadius() << endl;
}

void ex1028_3() {
	Circle3 waffle(30);
	increaseREF(waffle);
	cout << waffle.getRadius() << endl;
}

void Swap(Circle3& A, Circle3& B) {
	Circle3 tmp = A;
	A = B;
	B = tmp;
}

void ex1028_4() {
	Circle3 A(30), B(10);
	Swap(A, B);
	cout << "A : " << A.getRadius() << endl;
	cout << "B : " << B.getRadius() << endl;
}

void readRadius(Circle3& cir) {
	cout << "input : ";

	int tmp;
	cin >> tmp;

	cir.setRadius(tmp);
}

void ex1028_5() {
	Circle3 donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
}

void ex1031_1() {
	int* a = new int[10];
	int* b;

	for (int i = 0; i < 10; i++) {
		a[i] = i * 10;
	}

	b = a;		// ���� ����

	delete[] a;
}

void ex1031_2() {		// ���� ����
	int* a = new int[10];
	int* b;
	for (int i = 0; i < 10; i++) {
		a[i] = i * 10;
	}
	b = new int[10];
	for (int i = 0; i < 10; i++) {
		b[i] = a[i];
	}
	delete[] b;
	delete[] a;
}

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};

Accumulator::Accumulator(int value) {
	this->value = value;
}

Accumulator& Accumulator::add(int n) {
	this->value += n;
	return *this;
}

int Accumulator::get() {
	return value;
}

void ex1031_3() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get() << endl;
}

class Book {
	char* title;
	int price;
public:
	Book(char* title, int price);
	Book(Book& obj);		// ���� ������
	~Book();
	void operator+=(int value) {
		this->price += value;
	}
	void operator-=(int value) {
		this->price -= value;
	}
	bool operator!() {
		if (this->price == 0) { return true; }
		else { return false; }
	}
	friend bool operator==(Book& A, int price);
#if 0
	bool operator==(int price) {
		if (this->price == price) { return true; }
		else { return false; }
	}
#endif
	void set(char* title, int price);
	void show() { cout << title << " " << price << "��" << endl; }
};
bool operator==(Book& A, int price) {
	if (A.price == price) { return true; }
	else { return false; }
}

Book::Book(char* title, int price) {
	this->price = price;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
}

Book::Book(Book& obj) {

}

Book::~Book() {
	delete[] this->title;
	cout << "�Ҹ���" << endl;
}

void Book::set(char* title, int price) {
	this->price = price;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
}

void ex1031_4() {
	Book cpp((char*)"��ǰC++", 10000);
	Book java = cpp;
	java.set((char*)"��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}

class Book2 {
	char title[100];
	int price;
public:
	Book2(char* title, int price);
	~Book2();
	void set(char* title, int price);
	void show() {
		cout << title << " " << price << "��" << endl;
	}
};

Book2::Book2(char* title, int price) {
	strcpy(this->title, title);
	this->price = price;
}

Book2::~Book2() {
	cout << "�Ҹ���" << endl;
}

void Book2::set(char* title, int price) {
	strcpy(this->title, title);
	this->price = price;
}

void ex1104_1() {
	Book2 cpp((char*)"��ǰC++", 10000);
	Book2 java = cpp;
	java.set((char*)"��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width; this->height = height;
	}
	bool equals(Rect s);
};

bool Rect::equals(Rect s) {
	if (this->width == s.width && this->height == s.height) { return true;  }
	else { return false; }
}

void ex1104_2() {
	Rect a(3, 4), b(4, 5);
	if (a.equals(b)) /* equals(a, b) */ { cout << "����" << endl; }
	else { cout << "�ٸ���" << endl; }
}

class Rect2 {
	int width, height;
public:
	Rect2(int width, int height) {
		this->width = width; this->height = height;
	}
	friend bool equals(Rect2 a, Rect2 b);
};
bool equals(Rect2 a, Rect2 b) {
	if (a.width == b.width && a.height == b.height) {
		return true;
	}
	else {
		return false;
	}
}
void ex1104_3() {
	Rect2 a(2, 3), b(3, 4);
	if (equals(a, b)) { cout << "����" << endl; }
	else { cout << "�ٸ���" << endl; }
}

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show() {
		cout << "kick = " << kick << ", punch = " << punch << endl;
	}
	Power operator+(Power input) {
		Power tmp;
		tmp.kick = this->kick + input.kick;
		tmp.punch = this->punch + input.punch;
		return tmp;
	}
	Power operator-(Power input) {
		Power tmp;
		tmp.kick = this->kick - input.kick;
		tmp.punch = this->punch - input.punch;
		return tmp;
	}
	bool operator==(Power input) {
		if (this->kick == input.kick && this->punch == input.punch) { return true; }
		else { return false; }
	}
};

void ex1104_4() {
	Power a(3, 5), b(4, 6), c, d;
	c = a + b; // a.operator + (b)
	d = b - a; // b.operator - (a)
	if (a == b) { cout << "����" << endl; }
	else { cout << "�ٸ���" << endl; }
	a.show();
	b.show();
	c.show();
	d.show();
}

#define PI 3.1415926535

class Complex {
	float re, im;
public:
	friend double getMag(Complex A);
	friend double getAngle(Complex A);
	Complex() { re = im = 0; }
	Complex(float re, float im) { this->re = re; this->im = im; }
	Complex operator+(Complex in) {
		Complex tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Complex operator-(Complex in) {
		Complex tmp;
		tmp.re = this->re - in.re;
		tmp.im = this->im - in.im;
		return tmp;
	}
	Complex operator*(Complex in) {
		double mag = getMag(*this) * getMag(in);
		double angle = getAngle(*this) + getAngle(in);
		return convert2Cartersian(mag, angle);
	}
	Complex operator/(Complex in) {
		double mag = getMag(*this) / getMag(in);
		double angle = getAngle(*this) - getAngle(in);
		return convert2Cartersian(mag, angle);
	}
	void show() {
		cout.precision(5);
		if (im >= 0) {
			cout << re << " +j" << im << endl;
		}
		else {
			cout << re << " -j" << -im << endl;
		}
	}
	Complex convert2Cartersian(double mag, double angle) {
		Complex tmp;
		tmp.re = mag * cos(angle);
		tmp.im = mag * sin(angle);
		return tmp;
	}
#if 0
	double getMag(Complex A) { return sqrt(re * re + im * im); }
	double getAngle(Complex A) {
		if (re == 0 && im == 0) { return 0.0; }
		else if (re == 0 && im > 0) { return PI / 2.0; }
		else if (re == 0 && im < 0) { return PI / -2.0; }
		else { return atan(im / re); }
	}
	Complex convert2Cartersian(double mag, double angle) {
		Complex tmp;
		tmp.re = mag * cos(angle);
		tmp.im = mag * sin(angle);
		return tmp;
	}
#endif
};
double getMag(Complex A) { return sqrt(A.re * A.re + A.im * A.im); }
double getAngle(Complex A) {
	if (A.re == 0 && A.im == 0) { return 0.0; }
	else if (A.re == 0 && A.im > 0) { return PI / 2.0; }
	else if (A.re == 0 && A.im < 0) { return PI / -2.0; }
	else { return atan(A.im / A.re); }
}
void ex1104_5() {
	Complex a(2, 3), b(3, 4), c, d, e, f;
	c = a + b;
	c.show();
	d = a - b;
	d.show();
	e = a * b;				// ũ��� ���ϰ� ������ ����.
	e.show();
	f = a / b;
	f.show();
}

void ex1107_1() {
	Book a((char*)"û��", 20000), b((char*)"�̷�", 30000);
	a += 5000;			// a.operator += (5000)
	b -= 5000;			// b.operator -= (5000)

	a.show();
	b.show();
}

class Power2 {
	int kick;
	int punch;
public:
	Power2(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show() {
		cout << "kick = " << kick << ", punch = " << punch << endl;
	}
	friend Power2 operator+(Power2 A, Power2 B);
	friend Power2 operator-(Power2 A, Power2 B);
};

Power2 operator+(Power2 A, Power2 B) {
	Power2 tmp;
	tmp.kick = A.kick + B.kick;
	tmp.punch = A.punch + B.punch;
	return tmp;
}

Power2 operator-(Power2 A, Power2 B) {
	Power2 tmp;
	tmp.kick = A.kick - B.kick;
	tmp.punch = A.punch - B.punch;
	return tmp;
}

void ex1107_2() {
	Power2 a(3, 5), b(4, 6), c, d;
	/*c = a + b;*/		// �Ŀ���ü + ����
	c = operator+(a, b);
	d = a - b;
	a.show();
	b.show();
	c.show();
	d.show();
}

void ex1111_1() {
	Book a((char*)"û��", 20000), b((char*)"�̷�", 30000);
	if (a == 30000) { cout << "���� 30000��" << endl; }
	else { cout << "30000���� �ƴϴ�." << endl; }
}

void ex1111_2() {
	Book book((char*)"�������", 0);
	if (!book) { cout << "��¥��" << endl; }
}

class Point {
	int x, y; //�� �� (x,y) ��ǥ��
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point {		// �θ� : �ڽ�
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << ":";
		showPoint();
	}
};

void ex1111_3() {
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("RED");
	cp.showColorPoint();

	ColorPoint* pDer = &cp;
	pDer->set(30, 40);		// (*pDer).set(30, 40);
	pDer->setColor("BLUE");
	pDer->showColorPoint();

	Point* pBase = pDer;
	pBase->set(300, 400);
	pDer->showColorPoint();
}

void ex1111_4() {
	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp;

	pBase->set(3, 4);
	pBase->showPoint();

	pDer = (ColorPoint*)pBase;
	pDer->set(30, 40);
	pDer->showColorPoint();
	pDer->showPoint();
}

class Circle4 {
private:
	int radius;
public:
	Circle4() { radius = 1; }
	Circle4(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle : public Circle4 {
	string name;
public:
	NamedCircle() {
		setRadius(0);
		name = "NULL";
	}
	NamedCircle(int radius, string name) {
		setRadius(radius);
		this->name = name;
	}
	void setNamedCircle(int radius, string name) {
		setRadius(radius);
		this->name = name;
	}
	void show() {
		cout << "�������� " << getRadius() << "�� " << name << endl;
	}
	friend void FindLargestNamedCircle(NamedCircle* namedcircle, int size);
};

void ex1111_5() {
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	waffle.show();
}

void FindLargestNamedCircle(NamedCircle* namedcircle, int size) {
	int r_max = namedcircle[0].getRadius();
	int index_max = 0;
	for (int i = 1; i < 5; i++) {
		if (namedcircle[i].getRadius() > r_max) {
			r_max = namedcircle[i].getRadius();
			index_max = i;
		}
	}
	cout << "���� ������ ū ���ڴ� �ݰ��� " << r_max << "��" << namedcircle[index_max].name << "�̴�" << endl;
}

void ex1114_1() {
	NamedCircle pizza[5];
	string pizza_name[5];
	int pizza_radius[5];
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i < 5; i++) {
		int radius = 1;
		string name;
		cin >> radius;
		cin >> name;
		pizza[i].setNamedCircle(radius, name);
	}
	FindLargestNamedCircle(pizza, 5);
}

class BaseArray {
private:
	int capacity; // ���� �Ҵ�� �޸� �뷮
	int* mem; // ���� �迭�� ����� ���� �޸� ������
protected:
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
	void MakeQueue(int capacity) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
public:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
};

class MyQueue : public BaseArray {
	int index = 0;
public:
	MyQueue(int cap) {
		MakeQueue(cap);
	}
	void enqueue(int n) {
		put(index, n);
		index++;
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return index;
	}
	int dequeue() {
		int value = get(0);
		index--;
		for (int i = 0; i < index; i++) {
			// get(i) = get(i + 1);
			put(i, get(i + 1));
		}
		return value;
	}
};
void ex1114_2() {
	MyQueue mQ(100);
	int n;

	cout << "ť�� ������ 5���� ������ �Է��϶� >> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

class AA {
public:
	AA() { cout << "Constructor A" << endl; }
	~AA() { cout << "Destructor A" << endl; }
};
class BB : public AA {
public:
	BB() { cout << "Constructor B" << endl; }
	~BB() { cout << "Destructor B" << endl; }
};
class CC : public BB {
public:
	CC() { cout << "Constructor C" << endl; }
	~CC() { cout << "Destructor C" << endl; }
};
void ex1118_1() {
	CC c;
}

class AAA {
public:
	AAA() { cout << "Constructor A" << endl; }	// (1)
	AAA(int x) { cout << "Constructor A(int x)" << endl; }	// (2)
	~AAA() { cout << "Destructor A" << endl; }
};
class BBB : public AAA {
public:
	BBB() { cout << "Constructor B" << endl; }	// (3)
	BBB(int x) : AAA() { cout << "Constructor B(int x)" << endl; }	//(4)
	~BBB() { cout << "Destructor B" << endl; }
};

void ex1118_2() {
	BBB b;		// (1) (3)
	BBB bb(5);	// (1) (4) <-- ������ �� AAA�� �⺻�����ڰ� ȣ���
}

class AAAA {
public:
	AAAA() { cout << "Constructor A" << endl; }	// (1)
	AAAA(int x) { cout << "Constructor A(int x) : " << x << endl; }	// (2)
	~AAAA() { cout << "Destructor A" << endl; }
};
class BBBB : protected AAAA {
public:
	BBBB() { cout << "Constructor B" << endl; }	// (3)
	BBBB(int x) : AAAA(x) { cout << "Constructor B(int x) : " << x << endl; }	//(4)
	~BBBB() { cout << "Destructor B" << endl; }
};
// virtual ������ ������� ����
void ex1118_3() {
	BBBB b;	// (1) (3)
	BBBB bb(5);	// (2) (4)
}

void main() {

}