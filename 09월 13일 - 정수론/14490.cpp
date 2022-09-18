#include <iostream>
#include <string>

using namespace std;

int gcd(int x, int y) {

	for (int i = min(x, y); i > 0; i--) {
		if (x % i == 0 && y % i == 0) {
			return i;
		}
	}

	return 1;
}

string getResult(string s) {
	string x, y, result;
	bool check = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ':') {
			(check == false) ? x += s[i] : y+= s[i];
		}

		else  check = true;
	}

	int g = gcd(stoi(x), stoi(y));  // 최대공약수 g

	result = to_string(stoi(x) / g) + ":" + to_string(stoi(y) / g);

	return result;
}

int main() {

	string input;
	cin >> input;

	cout << getResult(input) << "\n";

	return 0;
}