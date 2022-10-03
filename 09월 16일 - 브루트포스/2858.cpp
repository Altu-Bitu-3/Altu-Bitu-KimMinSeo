#include <iostream>

using namespace std;

void printRoomSize(int r, int b) {

	/*  조건 2가지
		(1)   w * l = r + b
		(2)   2*w + 2*l - 4 = r  
	*/

	for (int i = 3; i <= (r + b) / 3; i++) {           //  조건(1) 의해서 범위 설정
		for (int j = 3; j <= (r + b) / 3; j++) {
			if (i * j == r + b && 2*i + 2*j - 4 == r) {
				cout << max(i, j) << " " << min(i, j) << "\n";
				return;
			}
		}
	}
}

int main() {

	int r, b;            // 빨간색 타일, 갈색 타일
	cin >> r >> b;

	printRoomSize(r, b);

	return 0;
}