#include <iostream>
#include <string>

using namespace std;

string add(string &a, string &b) {
	string longer, result;
	longer = (a.size() >= b.size()) ? a : b;

	// 자릿수 같도록 맞춰주기
	while (a.size() < longer.size()) {
		a = '0' + a;
	}

	while (b.size() < longer.size()) {
		b = '0' + b;
	}


	string sum;
	int next = 0;

	for (int i = 0 ; i < longer.size() ; i++) {
		int idx = longer.size() - i - 1;
		
		sum = to_string((a[idx] - '0') + (b[idx] - '0') + next);
		
		next = (sum.size() > 1) ? 1 : 0;    // sum이 두자리수면 next는 1

		result = sum.back() + result;
	}

	result = (next == 0) ? result : '1' + result;   // 맨 앞자리수 처리

	
	return result;
}

int main() {
	string a, b;
	cin >> a >> b;

	string result = add(a, b);

	cout << result << "\n";

	return 0;
}