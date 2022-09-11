#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	set<string> s;
	string input;

	while (n--) {
		cin >> input;
		s.insert(input);
	}

	int result = 0;   // S에 포함된 문자열 개수
	while (m--) {
		cin >> input;
		if (s.find(input) != s.end()) result++;
	}

	cout << result << "\n";

	return 0;
}