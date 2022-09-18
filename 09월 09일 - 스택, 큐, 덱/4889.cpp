#include <iostream>
#include <stack>

using namespace std;

int minOp(const string& s) {
	int result = 0;    // 최소 연산 개수
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {

		// [case 1] 스택 비어 있음
		if (st.empty()) {

			if (s[i] == '}') {  // top이 '}'인 경우는 무조건 '{'으로 바꿔야 안정적
				result++;
				st.push('{');
			}
			
			else st.push(s[i]);
		}


		// [case 2] 스택 비어있지 않음
		else {
			if (s[i] != st.top()) st.pop();    // 짝이 맞는 경우
			else  st.push(s[i]);               // 짝이 맞지 않는 경우
		}
	}

	result += st.size() / 2;  // 스택에 남은 '{'들 중 절반을 '}'으로 바꾸면 안정적 
	
	return result;
}


int main() {

	int num = 0;   // 테스트 케이스 개수
	string input;
	cin >> input;

	while (input[0] != '-') {
		num++;
		cout << num << ". " << minOp(input) << "\n";

		cin >> input;
	}

	return 0;
}