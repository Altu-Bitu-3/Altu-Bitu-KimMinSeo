#include <iostream>
#include <map>
#include <vector>

using namespace std;

void calculate(map<string, int>& m) {
	int num_result = 1;       // 의상 조합 경우의 수

	for (auto iter : m) {
		num_result *= (iter.second + 1);
	}

	num_result--;  // 알몸인 경우 제외
	cout << num_result << "\n";
}

int main() {

	int n;   // 테스트 케이스 개수
	cin >> n;

	int c;   // 가진 의상의 수
	string item, type;  // 의상 이름, 의상 종류

	map<string, int> m;  //  key : 의상 종류, value : key 타입의 의상 개수

	while (n--) {
		cin >> c;

		while (c--) {
			cin >> item >> type;

			if (m.find(type) != m.end())  m[type]++;
			else m[type] = 1;
		}

		if (m.size() == 1) cout << m.begin()->second << "\n";  // 의상 종류 1가지인 경우
		else calculate(m);

		m.clear();
	}

	return 0;
}