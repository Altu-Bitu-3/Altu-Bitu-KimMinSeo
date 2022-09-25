#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

using namespace std;

bool checkPrime(int k) {  //  소수 여부 판별

	if (k < 2) return false;

	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) return false;
	}

	return true;
}

bool checkSang(int k) {
	set<int> nums;
	string s = to_string(k);

	while (true) {
		int result = 0;

		for (int i = 0; i < s.size(); i++) {
			result += (s[i] - '0') * (s[i] - '0');
		}

		if (result == 1) return true;            // 1이 나오면 상근수

		if (nums.find(result) == nums.end()) {   // 결과 숫자가 처음 나온 경우
			nums.insert(result);
			s = to_string(result);
		}

		else  return false;  // 결과 숫자가 이전에 나온 적 있는 경우 (순환 -> 상근수 아님)

	}

	return false;
}

vector<int> getResult(int n) {
	vector<int> v;

	for (int i = 1; i < n; i++) {
		if (checkPrime(i) && checkSang(i)) 
			v.push_back(i);
	}

	return v;
}

int main() {

	int n;
	cin >> n;

	for (auto i : getResult(n)) {
		cout << i << "\n";
	}

	return 0;
}