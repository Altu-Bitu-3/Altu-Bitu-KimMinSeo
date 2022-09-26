#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getCharge(string& start, string& time) {
	int charge = 0; 

	// 자정 00:00으로부터 흐른 minute으로 통화 시작, 종료 시각 표현하기
	int call_start = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
	int call_fin = call_start + stoi(time);


	if (call_start >= 7 *60 && call_fin < 19 * 60) {
		charge += (stoi(time) * 10);
	}

	// 자정 넘어서 통화 시작하는 경우 추가해야 함
	if (call_start >= 19 * 60 && call_fin < 26 * 60 || call_start >= 0 && call_fin < 7 * 60) {
		charge += (stoi(time) * 5);
	}
	
	if (call_start < 7 * 60 && call_fin >= 7*60) {
		charge += (7 * 60 - call_start) * 5;
		charge += (call_fin - 7*60) * 10;
	}

	if (call_start < 19 * 60 && call_fin >= 19 * 60) {
		charge += (19*60 - call_start) * 10;
		charge += (call_fin - 19*60) * 5;
	}

	return charge;
}

int main() {

	int n;  // 전화의 수, 전화 요금
	cin >> n;

	int answer = 0;

	string start, time;
	while (n--) {
		cin >> start >> time;
		answer += getCharge(start, time);
	}

	cout << answer << "\n";

	return 0;
}