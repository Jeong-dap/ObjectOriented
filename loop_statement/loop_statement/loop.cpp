#include <iostream>
using namespace std;
int main() {
	int j = 0;
	do {
		cout << j << std::endl;
		j++;
	} while (j < 5);

	for (int k = 0; k < 5; k++) {
		if (k == 4) break;
		cout << k << std::endl;
	}
}