#include <iostream>
using namespace std;

int main() {
	int a;			// a를 int형 변수로 선언
	string name;	// name을 string형 변수로 선언
	char d;			// d를 char형 변수로 선언
	bool b;			// b를 bool형 변수로 선언
	int v[10];		// v를 int형 배열로 선언
	cout << "Hello World" << endl;	// 맨 처음 출력문에는 Hello World\n를 출력
	cout << "정수 a를 입력 >> ";
	cin >> a;	// a 입력문
	cout << "name을 입력 >> ";
	cin >> name;	// name 입력문
	cout << "문자 하나 입력 >> ";
	cin >> d;	// d 입력문
	cout << "숫자 9개를 입력 >> ";
	for (int i = 0; i < 9; i++) {
		cin >> v[i];	// v는 배열이므로 9개의 정수를 입력받음
	}
	cout << a << " " << name << " " << d << " ";	// 출력 a name d 순서로 출력
	for (int j = 0; j < 9; j++) {
		cout << v[j] << " ";	// v안에 숫자를 출력 " " 공백을 사용하여 구분
	}
}