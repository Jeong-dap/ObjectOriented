#include <iostream>
using namespace std;

int main() {
	int x, y;
	cout << "x를 입력하시오(1, 2)" << std::endl;	// x값 입력받기
	cin >> x;
	cout << "y를 입력하시오(1, 2)" << std::endl;	// y값 입력받기
	cin >> y;

	if (x < y) {
		cout << y << std::endl;		// x보다 y가 더 크게 되면 y값 출력
	}
	else if (x == y) {
		cout << "equal" << std::endl;	// 두 수가 같으면 equal 출력
	}
	else {
		cout << x << std::endl;		// y보다 x가 더 크게 되면 x값 출력
	}
	cout << (x < y) ? "x" : "y";	// 삼항 연산자

	switch (x) {
	case 1:
		cout << x << std::endl;		// x의 값이 1인 경우 x 값인 1 출력
		break;
	case 2:
		cout << y << std::endl;		// x의 값이 2인 경우 x 값인 2 출력
		break;
	default:
		cout << "Z" << std::endl;	// 1혹은 2가 아닌 경우 Z을 출력
	}
}