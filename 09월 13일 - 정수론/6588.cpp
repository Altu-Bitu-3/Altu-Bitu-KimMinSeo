#include <iostream>
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

string printGoldbach(int n) {
	string result = "Goldbach's conjecture is wrong.";
	set<int> isPrime;
	
	for (int i = 3; i < n; i++) {
		if (checkPrime(i)) isPrime.insert(i);   // 홀수인 소수이면 insert
	}

	for (auto num : isPrime) {
		if (isPrime.find(n - num) != isPrime.end()) {
			result = to_string(n) + " = " + to_string(num) + " + " + to_string(n - num);
			return result;
		}
	}

	return result;
}

int main() {

	int input;
	cin >> input;

	while (input != 0) {
		cout << printGoldbach(input) << "\n";
		cin >> input;
	}

	return 0;
}