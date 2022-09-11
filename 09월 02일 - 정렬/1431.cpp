#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	
	if (a.size() != b.size()) return a.size() < b.size();  // case 1

	int sum_a = 0, sum_b = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') sum_a += (a[i] - '0');
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] >= '0' && b[i] <= '9') sum_b += (b[i] - '0');
	}

	if (sum_a != sum_b) return sum_a < sum_b;  // case 2


	return a < b;  // case 3
	
}

int main() {

	int n;
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}