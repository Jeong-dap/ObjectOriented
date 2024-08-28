#include <iostream>
using namespace std;
int main() {
	string companies[4] = { "Apple", "Tesla", "Google", "Nvidia" };	// 배열의 크기 지정
	string cars[] = { "Hyundai", "Kia", "BMW" };	// 배열의 크기 미지정
	for (int i = 0; i < sizeof(companies) / sizeof(string); i++) {
		cout << companies[i] << "\n";
	}
	for (string car : cars) {
		cout << car << "\n";
	}
}