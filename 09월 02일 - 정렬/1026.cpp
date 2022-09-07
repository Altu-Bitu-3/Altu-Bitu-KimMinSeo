#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int> &A, vector<int> &B) {
	int max = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < A.size(); i++) {
		max += (A[i] * B[i]);
	}

	return max;
}

int main() {
	
	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	int result = getMax(A, B);

	cout << result << "\n";

	return 0;
}