#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Number {
	int num;
	int frequency = 1;
	int order;
};

void myMap(Number number, map<int, Number> &m) {
	int key = number.num;

	if (m.find(key) != m.end()) m[key].frequency++;   // 기존에 m에 존재하는 경우

	else m[key] = number;    // 기존에 m에 존재하지 않은 경우
}

bool cmp(const Number& a, const Number& b) {
	if (a.frequency != b.frequency) {
		return a.frequency > b.frequency;
	}

	return a.order < b.order;
}

int main() {

	int n, c;
	cin >> n >> c;    // 숫자 개수, 범위 숫자

	map<int, Number> m;   // key : 숫자, value : number 구조체
	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;

		Number number;
		number.num = input;
		number.order = i;

		myMap(number, m);
	}

	
	vector<Number> v;

	for (auto iter : m) {
		v.push_back(iter.second);
	}

	sort(v.begin(), v.end(), cmp);

	for (auto iter : v) {
		while(iter.frequency--) cout << iter.num << " ";
	}

	return 0;
}