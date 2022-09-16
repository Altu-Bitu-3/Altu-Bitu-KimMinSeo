#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string toPalindrome(const string& name) {
	string result = "";
	map<char, int> m;  // <알파벳, 등장횟수> 저장


	for (int i = 0; i < name.size(); i++) {
		if (m.find(name[i]) == m.end())  m[name[i]] = 1;
		else  m[name[i]]++;
	}


	char odd_char = '_';   // 한번만 등장한 알파벳 (odd_char == '_'이면 한번만 등장한 알파벳 없는 상태)
	int odd_num = 0;       // 홀수번 등장한 알파벳 종류 개수
	
	for (auto iter : m) {
		if (iter.second % 2 == 1) {
			odd_char = iter.first;
			odd_num++;
		}
	}

	// 팰린드롬 불가한 경우 : 홀수번 등장한 알파벳이 2개 이상 존재
	if (odd_num > 1)  return "I'm Sorry Hansoo";  
	

	// 팰린드롬 만들기
	string half = "";
	for (auto alphabet : m) {
		for(int i=0 ; i < alphabet.second/2 ; i++) {
			half += alphabet.first;
		}
	}

	result = (odd_char == '_') ? half : half + odd_char; 
	reverse(half.begin(), half.end());
	result += half;

	return result;
}


int main() {

	string name;
	cin >> name;

	cout << toPalindrome(name) << "\n";


	return 0;
}