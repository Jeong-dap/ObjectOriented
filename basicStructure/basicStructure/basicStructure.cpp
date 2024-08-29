#include <iostream>
using namespace std;

struct Human {	// 구조체 선언
	int age;	// 구조체 안에 age라는 변수 (int형)
	string name;// string 형으로 name이라는 변수
	int getAge() { return age; }	// int getAge() 함수 선언 return 값은 age
	string getName() { return name; }	// string getName() 함수 선언 return 값은 name
	void setAge(int _age);	// void setAge(int _age) 함수 선언 매개변수 _age
};
void Human::setAge(int _age) {		// Human이라는 구조체의 멤버 함수 setAge
	age = _age;		// age라는 값에 _age의 값을 할당
}
int main() {
	struct {	// car1, car2 구조체 선언
		string brand;	// brand 이름을 string형으로 선언
		string model;	// model 이름을 string형으로 선언
		int year;		// 연식을 int형으로 선언
	} car1, car2;
	Human kim;	// Human 구조체의 이름을 kim으로 선언
	Human park;	// Human 구조체의 이름을 park으로 선언

	kim.name = "Kim";
	kim.age = 26;

	park.name = "Park";
	park.age = 23;

	car1.brand = "Kia";
	car1.model = "K5";
	car1.year = 2010;

	car2 = { "Tesla", "Model X", 2015 };	// 다음과 같이 배열의 형태로 초기화가 가능

	cout << kim.name << ", " << kim.age << endl;
	cout << park.name << ", " << park.age << endl;
	cout << car1.brand << ", " << car1.model << ", " << car1.year << endl;
	cout << car2.brand << ", " << car2.model << ", " << car2.year << endl;
}