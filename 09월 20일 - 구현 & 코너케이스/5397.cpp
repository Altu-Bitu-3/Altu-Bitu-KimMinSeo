#include <iostream>
#include <stack>

using namespace std;

string printPW(string input) {
	//   [   left stack  <-] [커서] [->  right stack   ] 
	stack<char> left;    // 커서 기준 왼쪽 문자들
	stack<char> right;   // 커서 기준 오른쪽 문자들
	char temp;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<' && !left.empty()) {
			temp = left.top();
			right.push(temp);
			left.pop();
		}

		else if (input[i] == '>' && !right.empty()) {
			temp = right.top();
			left.push(temp);
			right.pop();
		}

		else if (input[i] == '-' && !left.empty()) {
			left.pop();
		}

		else if(input[i] >= 'A' && input[i] <= 'z') {  // 알파벳인 경우
			left.push(input[i]);    
		}
	}

	// 최종 비밀번호 출력
	string answer = "";
	while (!left.empty()) {
		answer = left.top() + answer;
		left.pop();
	}

	while (!right.empty()) {
		answer += right.top();
		right.pop();
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;  // 테스트 케이스 개수
	cin >> n;

	string input;

	while (n--) {
		cin >> input;
		cout << printPW(input) << "\n";
	}

	return 0;
}