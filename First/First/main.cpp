#include <iostream>
int add(int x, int y);
int main() {
	int x = 123;	// initialization

	x = 5;	// assignment

	std::cout << x << std::endl;	// endlÀº ÁÙ¹Ù²Ş
	std::cout << add(x, x) << std::endl;

	return 0;
}
int add(int x, int y) {
	return x + y;
}