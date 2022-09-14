#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {

	long long result = 0;     //  10,000 * 10,000의 경우, int 범위 넘어갈 수 있음을 놓쳤었음

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());  // 주려고 했던 금액이 큰 고객이 앞에 오게 정렬

	for (int i = 0; i < n; i++) {
		int tip = v[i] - i;

		if (tip >= 0) result += tip;
	}

	cout << result;

	return 0;
}