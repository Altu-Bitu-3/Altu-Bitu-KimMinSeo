#include <iostream>

using namespace std;

int gcd(int a, int b) {
	for (int i = min(a, b); i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}

	return 1;
}

int getNum(int x, int y) {
	int result = 0;
	int g = gcd(x, y);

	result = g * (x / g + y / g - 1);  // gcd * (단위 직사각형의 가로 + 세로 - 1)

	return result;
}

int main() {

	int x, y;      // 가로, 세로
	cin >> x >> y;

	cout << getNum(x, y) << "\n";

	return 0;
}