#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> wheel;     // 바퀴 칸별 문자 저장
int idx_arrow = 0;      // 현재 화살표가 가리키는 칸의 인덱스
bool valid = true;      // 종이에 해당하는 행운의 바퀴 있는지 여부 


void updateState(int& idx_arrow, int change, char alphabet, int n) {
	idx_arrow = (idx_arrow + change) % n;

	// 지금 알파벳이 들어갈 자리에 이미 다른 알파벳이 있는 경우
	if (wheel[idx_arrow] != '?' && wheel[idx_arrow] != alphabet) {
		valid = false;
		return;
	}

	else  wheel[idx_arrow] = alphabet;
}

int main() {

	int n, k;        // 바퀴 칸 수 n, 회전 횟수 k
	cin >> n >> k;

	wheel.assign(n, '?');


	int change;
	char alphabet;

	while (k-- && valid) {
		cin >> change >> alphabet;
		updateState(idx_arrow, change, alphabet, n);
	}
	
	// 원래는 돌리면 반시계방향에서 숫자가 넘어온다. 따라서 reverse로 순서 재정렬
	reverse(wheel.begin(), wheel.end());  
	idx_arrow = n-1 - idx_arrow;


	// 같은 알파벳이 중복으로 들어가있는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (wheel[i] != '?' && wheel[i] == wheel[j]) {
				valid = false;
			}
		}
	}


	// [case 1] 종이에 해당하는 행운의 바퀴 없는 경우
	if (!valid) {
		cout << "!" << "\n";
		return 0;
	}

	// [case 2] 종이에 해당하는 행운의 바퀴 있는 경우
	int idx;
	for (int i = 0; i < n; i++) {
		cout << wheel[(i + idx_arrow) % n];
	}

	return 0;
}