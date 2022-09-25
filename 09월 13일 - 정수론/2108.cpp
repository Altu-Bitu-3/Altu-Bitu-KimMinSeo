#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getAvg(vector<int>& v) {
	int avg = 0;

	for (auto iter : v) {
		avg += iter;
	}

	avg = floor((double)avg/v.size() + 0.5);  // 반올림
	return avg;
}

int getMed(vector<int>& v) {
	int med = 0;
	
	// 정수가 짝수개인 경우
	if (v.size() % 2 == 0) {   
		med = v[v.size() / 2 - 1] + v[v.size() / 2];
		med = floor(med/2 + 0.5);
	}

	// 정수가 홀수개인 경우
	else med = v[v.size() / 2];
	
	return med;
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int getMode(map<int, int>& m) {
	int mode = 0, maxFreq = 0;       // maxFreq : 최대 빈도수
	vector<pair<int, int>> v;        // <정수, 빈도수> 저장

	for (auto iter : m) {
		v.push_back(make_pair(iter.first, iter.second));
		maxFreq = max(maxFreq, iter.second);
	}

	sort(v.begin(), v.end(), cmp);

	mode = (v.size() > 1 && v[1].second == maxFreq) ? v[1].first : v[0].first;

	return mode;
}

int getRange(int minNum, int maxNum) {
	return maxNum - minNum;
}


int main() {

	int n;             // 입력 정수 개수
	cin >> n;

	vector<int> v;     // 정수 저장
	map<int, int> m;   // <정수, 빈도수> 저장

	int num;
	while (n--) {
		cin >> num;
		v.push_back(num);

		if (m.find(num) == m.end()) m[num] = 1;
		else m[num]++;
	}

	sort(v.begin(), v.end());  // 정수들을 크기 순으로 정렬

	cout << getAvg(v) << "\n";
	cout << getMed(v) << "\n";
	cout << getMode(m) << "\n";
	cout << getRange(v.front(), v.back()) << "\n";

	return 0;
}