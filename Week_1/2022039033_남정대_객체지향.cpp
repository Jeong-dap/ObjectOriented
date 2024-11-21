#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;
int sum(int a, int b);
int ex0909() {
	int n;
	cout << "끝수를 입력하세요 >> ";
	cin >> n;
	if (n <= 0) {
		cout << " 양수를 입력하세요!\n";
		return 0;
	}
	cout << "1에서 "<< n << "까지의 합은" << sum(1, n) << "입니다.\n";
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
	cout << "7 개의 실수를 입력하라 >> ";
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

	//////////////////////////////////// 비추 코드 /////////////////////////////////////////
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
//////////////////////////////////////포인터///////////////////////////////////////
void pfunc_1_(int* a, int* b) {			// 주소값도 포함하는 *a, *b를 선언
	cout << *a << " " << *b << endl;
	*a = 30, * b = 40;					// 그냥 a와 그냥 b는 주소값이므로 *a에 30 대입, *b 에 40 대입
}
//////////////////////////////////// 레퍼런스///////////////////////////////////////
void pfunc_2_(int& c, int& d) {			// 주소라는 의미가 아아니고 레퍼런스 기호
	cout << c << " " << d << endl;
	c = 30, d = 40;
}
void ex0919_2() {
	int a = 10, b = 20;
	pfunc_1_(&a, &b);	// 주소를 전달
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
	cout << "평균은 " << avg << endl;
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
	cout << "두 정수를 입력하세요 >> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b) { cout << "same" << endl; }
	else { cout << "큰 수는 " << big << endl; }
}

int sum3(int a, int b = 200, int c = 100) {		// default 인자를 줄때는 오른쪽부터 지정 & 생략한다.
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
	myswap(a, b); // myswap(int& a, int& b) 호출
	cout << a << '\t' << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) 호출
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
private:			///////////////////////// private과 public에서 아무것도 적지 않으면 private으로 들어감 //////////
	
public:
	int radius;
	double getArea() {
		double area = 3.14 * radius * radius;		// class에 radius가 선언되어 있으므로 그냥 사용 가능
		return area;
	}
};

//double Circle::getArea() {
//	double area = 3.14 * radius * radius;		// class에 radius가 선언되어 있으므로 그냥 사용 가능
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
	cout << "사각형의 면적은 " << rect.getArea() << endl;
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
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}

class Circle2 {
public:
	int radius;
	Circle2();
	Circle2(int r);
	~Circle2();			// 소멸자 ==> 소멸은 생성의 역순으로 작동
	double getArea();	// 멤버함수 == *메소드(method)
};

Circle2::~Circle2() {			// 소멸자
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

Circle2::Circle2() {			// 기본 생성자
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle2::Circle2(int r) {		// 매개변수를 받는 생성자
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle2::getArea() {		// 원의 넓이를 반환하는 함수
	return 3.14 * radius * radius;
}

void ex0930_1() {
	Circle2 donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle2 pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은" << area << endl;
}
void func0930();

void ex0930_2() {
	func0930();
	Circle2 pizza(30);	// (2)
	double area = pizza.getArea();
	cout << "pizza 면적은" << area << endl;

}
void func0930() {
	Circle2 donut;	// (1)
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;
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
		cout << "소멸" << width << " " << height << endl;
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

	if (rect1.isSquare()) { cout << "rect1은 정사각형이다." << endl; }
	if (rect2.isSquare()) { cout << "rect2은 정사각형이다." << endl; }
	if (rect3.isSquare()) { cout << "rect3은 정사각형이다." << endl; }
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
	~Oval() { cout << "Oval 소멸 : width = " << width << ", height = " << height << endl; }
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
	if (isEven(A)) { cout << A << "은(는) 짝수다!"; }	// if (isEven(A) == true)와 같은 역할
	else { cout << A << "은(는) 홀수다!"; }
}

//#include "cal.h"

class Cal {
public:
	void run();
};

//void Cal::run() {
//	cout << "두 개의 수를 입력하세요 >> ";
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
	char mem[100 * 1024]; // 100KB 메모리
	int size;
public:
	Ram(); // mem을 0으로 초기화하고 size를 100*1024로 초기화	// 생성자
	~Ram(); // "메모리 제거됨" 문자열 출력		// 소멸자
	char read(int address); // address 주소의 메모리를 읽어 리턴
	void write(int address, char value); // address 주소에 value 저장
	// 주소가 범위를 벗어나는 오류 발생하면 에러메시지 출력함.
};

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}

Ram::~Ram() { cout << "메모리 제거됨" << endl; }

char Ram::read(int address) { return mem[address]; }

void Ram::write(int address, char value) { mem[address] = value; }

void ex1007_2() {
	Ram ram;
	ram.write(100, 20); // 100 번지에 20 저장
	ram.write(101, 30); // 101 번지에 30 저장
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 번지에 50 저장
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 메모리 값 출력
}

// static : 정적
// dynamic : 동적

//class Person {
//public:
//	double money; // 개인 소유의 돈
//	void addMoney(int money) {
//		this->money += money;
//	}
//	Person() { money = 0; }
//	static int sharedMoney; // 공금
//	static void addShared(int n) {
//		sharedMoney += n;
//	}
//};
//// static 변수 생성. 전역 공간에 생성
//int Person::sharedMoney = 10; // 10으로 초기화

//void ex1007_3() {
//	Person han;
//	han.money = 100; // han의 개인 돈=100
//	han.sharedMoney = 200; // static 멤버 접근, 공금=200
//
//	Person lee;
//	lee.money = 150; // lee의 개인 돈=150
//	lee.addMoney(200); // lee의 개인 돈=350
//	lee.addShared(200); // static 멤버 접근, 공금=400
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
	static void addShared(int sharedmoney_in) {		// static 멤버 변수를 받기 때문에 static 멤버 함수로 선언
		sharedMoney += sharedmoney_in;
	}
	~Person2() {
		cout << name << "'s money = " << money << endl;
	}
};

int Person2::sharedMoney = 0;		// static 변수는 class 내에서 초기화 할 수 없으므로 class 밖에서 초기화

void ex1010_2() {
	Person2 A("KANG"), B("KIM");
	// 3월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	// 4월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "공금 = " << Person2::sharedMoney << endl;
	Person2::addShared(100);
	cout << "공금 = " << Person2::sharedMoney << endl;
}

void ex1010_3() {
	Person2 A("KANG"), B("KIM");
	// 3월
	A.addMoney(100);
	A.addShared(5);

	Person2* p = &A;

	cout << A.money << ' ' << (*p).money << ' ' << p->money << endl;
//p : 주소
//&A : 객체
//A : 객체
//*p : 객체(p가 가르키고 있는 객체)
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
	p->show();	// (*p).show(); 이것과 같다.
	Color colors[3];
	p = colors;

	p->setColor(255, 0, 0);			// colors[0].setColor(255, 0, 0);	p[0].setColor(255, 0, 0);	세 개 모두 같음
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
	int* A = (int*)malloc(number * sizeof(int));		// 메모리 할당
	A[0] = 100; A[1] = 200; A[2] = 300; A[3] = 400; A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d %d", A[i], *(A + i));
	}
	free(A);	// 메모리 할당 해제
}

void ex1014_4(int number) {
	int* A = new int[number];	/*(int*)malloc(5 * sizeof(int));*/		// 메모리 할당
	A[0] = 100; A[1] = 200; A[2] = 300; A[3] = 400; A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d %d", A[i], *(A + i));
	}
	delete[] A;	// new 전용 메모리 할당 해제
	//free(A); malloc 전용 메모리 할당 해제
}

void ex1014_5() {
	Circle2* p, * q;
	p = new Circle2;
	q = new Circle2(10);

	cout << p->getArea() << endl;	// (*p).getArea()과 동일
	cout << q->getArea() << endl;	// (*q).getArea()과 동일

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
	cout << name << " 가족은 다음과 같이 " << size << "명 입니다." << endl;
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
//////////////// 기말고사 ///////////////
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
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle3::Circle3(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle3::~Circle3() {
	cout << "소멸자 실행 radius = " << radius << endl;
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
	cout << "donut의 면적 = " << donut.getArea() << endl;
}

void ex1031_1() {
	int* a = new int[10];
	int* b;

	for (int i = 0; i < 10; i++) {
		a[i] = i * 10;
	}

	b = a;		// 얕은 복사

	delete[] a;
}

void ex1031_2() {		// 깊은 복사
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
	Book(Book& obj);		// 복사 생성자
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
	void show() { cout << title << " " << price << "원" << endl; }
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
	cout << "소멸자" << endl;
}

void Book::set(char* title, int price) {
	this->price = price;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
}

void ex1031_4() {
	Book cpp((char*)"명품C++", 10000);
	Book java = cpp;
	java.set((char*)"명품자바", 12000);
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
		cout << title << " " << price << "원" << endl;
	}
};

Book2::Book2(char* title, int price) {
	strcpy(this->title, title);
	this->price = price;
}

Book2::~Book2() {
	cout << "소멸자" << endl;
}

void Book2::set(char* title, int price) {
	strcpy(this->title, title);
	this->price = price;
}

void ex1104_1() {
	Book2 cpp((char*)"명품C++", 10000);
	Book2 java = cpp;
	java.set((char*)"명품자바", 12000);
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
	if (a.equals(b)) /* equals(a, b) */ { cout << "같다" << endl; }
	else { cout << "다르다" << endl; }
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
	if (equals(a, b)) { cout << "같다" << endl; }
	else { cout << "다르다" << endl; }
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
	if (a == b) { cout << "같다" << endl; }
	else { cout << "다르다" << endl; }
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
	e = a * b;				// 크기는 곱하고 각도는 더함.
	e.show();
	f = a / b;
	f.show();
}

void ex1107_1() {
	Book a((char*)"청춘", 20000), b((char*)"미래", 30000);
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
	/*c = a + b;*/		// 파워객체 + 연산
	c = operator+(a, b);
	d = a - b;
	a.show();
	b.show();
	c.show();
	d.show();
}

void ex1111_1() {
	Book a((char*)"청춘", 20000), b((char*)"미래", 30000);
	if (a == 30000) { cout << "정가 30000원" << endl; }
	else { cout << "30000원이 아니다." << endl; }
}

void ex1111_2() {
	Book book((char*)"벼룩시장", 0);
	if (!book) { cout << "공짜다" << endl; }
}

class Point {
	int x, y; //한 점 (x,y) 좌표값
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point {		// 부모 : 자식
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
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	friend void FindLargestNamedCircle(NamedCircle* namedcircle, int size);
};

void ex1111_5() {
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
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
	cout << "가장 면적이 큰 피자는 반경이 " << r_max << "인" << namedcircle[index_max].name << "이다" << endl;
}

void ex1114_1() {
	NamedCircle pizza[5];
	string pizza_name[5];
	int pizza_radius[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
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
	int capacity; // 동적 할당된 메모리 용량
	int* mem; // 정수 배열을 만들기 위한 메모리 포인터
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

	cout << "큐에 삽입할 5개의 정수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
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
	BBB bb(5);	// (1) (4) <-- 주의할 것 AAA의 기본생성자가 호출됨
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
// virtual 가상상속 시험범위 제외
void ex1118_3() {
	BBBB b;	// (1) (3)
	BBBB bb(5);	// (2) (4)
}

void main() {

}