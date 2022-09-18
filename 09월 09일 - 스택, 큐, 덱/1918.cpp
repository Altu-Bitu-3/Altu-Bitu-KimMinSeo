#include <iostream>
#include <stack>

using namespace std;

void toPostfix(const string& s) {
	string result = "";
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {

		// [case 1] 피연산자인 경우
		if (s[i]>= 'A' && s[i] <= 'Z') {
			result += s[i];
		}


		// [case 2] 연산자 or 괄호인 경우
		else  {
			if (st.empty() || s[i] == '(') st.push(s[i]); 

			else if(s[i] == ')') {
				while (!st.empty() && st.top() != '(') {   // st.top()을 알아보려면 !st.empty() 조건이 필수 (처음에 놓침)
					result += st.top();
					st.pop();
				}
				st.pop();  // 남은 '(' 제거
			}

			else if (s[i] == '*' || s[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					result += st.top();
					st.pop();
				}
				st.push(s[i]);
			}

			else if (!st.empty() && (s[i] == '+' || s[i] == '-')) {
				while (!st.empty() && st.top() != '(') {
					result += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}

	while (!st.empty()) {      // 남은 연산자 다 꺼내기
		result += st.top();
		st.pop();
	}

	cout << result << "\n";

}

int main() {

	string input;
	cin >> input;

	toPostfix(input);

	return 0;
}