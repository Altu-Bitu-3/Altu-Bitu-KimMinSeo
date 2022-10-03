#include <iostream>
#include <deque>
#include <stack>

using namespace std;

deque<int> card_d;
deque<int> card_s;
deque<int> ground_d;
deque<int> ground_s;


void win(string winner) {

	if (winner == "su") {
		while (!ground_d.empty()) {
			card_s.push_back(ground_d.back());
			ground_d.pop_back();
		}
	}

	if (winner == "do") {
		while (!ground_s.empty()) {
			card_d.push_back(ground_s.back());
			ground_s.pop_back();
		}
	}
}


string play(int m) {
	int gameCnt = 1;  // 진행 횟수

	while (true) {

		// 도도 카드 내려놓기
		ground_d.push_front(card_d.front());
		card_d.pop_front();
		if (card_d.empty()) break;               // 도도 카드 개수 0개 -> 수연 승리

		if (ground_d.front() == 5) win("do");    // 도도 승리 
		else if (!ground_s.empty() && ground_d.front() + ground_s.front() == 5) win("su");  // 수연 승리

		if (gameCnt == m) break;  // m번 다 끝나면 게임 종료
		else gameCnt++;
		

		// 수연 카드 내려놓기
		ground_s.push_front(card_s.front());
		card_s.pop_front();
		if (card_s.empty()) break;               // 수연 카드 개수 0개 -> 도도 승리

		if (ground_s.front() == 5) win("do");    // 도도 승리
		else if (!ground_d.empty() && ground_d.front() + ground_s.front() == 5) win("su");  // 수연 승리

		if (gameCnt == m) break;  // m번 다 끝나면 게임 종료
		else gameCnt++;
	};

	cout << card_d.size() << " ______" << card_s.size() << endl;

	if (card_d.size() > card_s.size()) return "do!";
	else if (card_d.size() < card_s.size()) return "su!";
	else return "dosu";
}

int main() {

	int n, m;
	cin >> n >> m;


	int input_d, input_s;
	while (n--) {
		cin >> input_d >> input_s;
		card_d.push_back(input_d);
		card_s.push_back(input_s);
	}

	cout << play(m) << "\n";

	return 0;
}