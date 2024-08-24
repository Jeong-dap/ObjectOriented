#include <iostream>
using namespace std;

void printName(string name) {
	cout << "Hello " << name;
}

int main() {
	int i = 4;
	float f = 4.0;
	double d = 4.0;
	bool b = true;
	string greeting = "Hello ";
	string answer;
	char first = greeting[0];
	int* pi = &i;
	void (*fp)(string);

	fp = printName;

	cout << greeting << "World!!" << std::endl;
	cin >> answer;
	cout << pi << std::endl;
	cout << &pi << std::endl;

	fp(answer);

	return 0;
}