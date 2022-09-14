#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

void printState(const vector<int>& action, int n) {
	deque<int> dq;     // 처음 손에 들린 카드 순서
	dq.push_back(1);   // 맨 마지막에 내려놓은 1 카드 다시 돌려놓고 시작
	int first, last;

	for (int i = 2; i <= n ; i++) {
		switch (action[i-1]) {

			// 맨 위에 카드 돌려놓기
			case 1:   
				dq.push_front(i);     
				break;

			// 위에서 두번째에 카드 돌려놓기
			case 2:   
				first = dq.front();  
				dq.pop_front();
				dq.push_front(i);
				dq.push_front(first);
				break;

			// 맨 아래에 카드 돌려놓기
			case 3:    
				dq.push_back(i);
				break;
		}
	}

	int state;
	while (!dq.empty()) {
		state = dq.front();
		dq.pop_front();
		cout << state << " ";
	}
}


int main() {

	int n;   // 카드 개수
	cin >> n;

	vector<int> action;  // 사용한 기술 목록
	int input;

	while (n--) {
		cin >> input;
		action.push_back(input);
	}

	reverse(action.begin(), action.end());
	printState(action, action.size());

	return 0;
}