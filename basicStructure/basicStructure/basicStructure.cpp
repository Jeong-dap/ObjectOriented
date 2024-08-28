#include <iostream>
using namespace std;

struct Human {
	int age;
	string name;
	int getAge() { return age; }
	string getName() { return name; }
	void setAge(int _age);
};
void Human::setAge(int _age) {
	age = _age;
}
int main() {
	struct {
		string brand;
		string model;
		int year;
	} car1, car2;
	Human kim;
	Human park;

	kim.name = "Kim";
	kim.age = 26;

	park.name = "Park";
	park.age = 23;

	car1.brand = "Kia";
	car1.model = "K5";
	car1.year = 2010;

	car2 = { "Tesla", "Model X", 2015 };

	cout << kim.name << ", " << kim.age << std::endl;
	cout << park.name << ", " << park.age << std::endl;
	cout << car1.brand << ", " << car1.model << ", " << car1.year << std::endl;
	cout << car2.brand << ", " << car2.model << ", " << car2.year << std::endl;
}