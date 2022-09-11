#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;      // 출입 기록의 수
	cin >> n;

	map<string, string> m;   // key : 이름, value : 상태

	string name, state;
	while (n--) {
		cin >> name >> state;
		m[name] = state;
	}

	vector<string> v;  // 현재 회사에 있는 사람의 이름 저장

	for (auto iter : m) {
		if (iter.second == "enter") v.push_back(iter.first);
	}

	sort(v.begin(), v.end(), greater<>());

	for (auto person : v) {
		cout << person << "\n";
	}

	return 0;
}