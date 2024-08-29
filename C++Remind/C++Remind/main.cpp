#include <iostream>
using namespace std;

int main() {
	int a;
	string name;
	char d;
	bool b;
	int v[10];
	cout << "Hello World" << endl;
	cout << "정수 a를 입력 >> ";
	cin >> a;
	cout << "name을 입력 >> ";
	cin >> name;
	cout << "문자 하나 입력 >> ";
	cin >> d;
	cout << "숫자 9개를 입력 >> ";
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	cout << a << " " << name << " " << d << " ";
	for (int j = 0; j < 9; j++) {
		cout << v[j] << " ";
	}
}