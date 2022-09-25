#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string getResult(const vector<string>& v) {
	double result_num = stod(v[0]);
	string result;

	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i] == "*") {
			result_num *= stod(v[i+1]);
			i++;
		}

		if (v[i] == "/") {
			result_num /= stod(v[i+1]);
			i++;
		}
	}

	result = (result_num - floor(result_num) > 0) ? "toothpaste" : "mint chocolate";

	return result;
}

int main() {

	int n;             // 숫자 개수
	cin >> n; 
	n += (n - 1);      // 전제 인풋 개수 (정수 + 연산자)


	vector<string> v;  // 전체 인풋 저장
	string input;

	while (n--) {
		cin >> input;
		v.push_back(input);
	}

	cout << getResult(v) << "\n";

	return 0;
}