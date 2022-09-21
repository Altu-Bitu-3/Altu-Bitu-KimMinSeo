#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int getDiffNum(vector<string>& v) {
	set<string> s;        // 서로 다른 단어 종류 저장

	// v의 원소 2개씩 비교하며 같은 단어인지 판단
	string word1, word2; 
	for (int i = 0; i < v.size(); i++) {
		word1 = v[i];
		string temp = word1 + word1;

		for (int j = i + 1; j < v.size(); j++) {
			word2 = v[j];

			if (word1.size() != word2.size())  continue;       // 길이 다르면 무조건 다른 단어

			for (int k = 1; k < word1.size(); k++) {
				if (word2 == temp.substr(k, word1.size())) {   // 같은 단어인 경우 대표단어 하나로 통일
					v[j] = v[i];
					break;
				}
			}
		}
	}

	for (auto i : v) {    // 중복 없이 단어 종류 저장 
		s.insert(i);
	}

	return s.size();
}

int main() {

	int n;   // 단어 개수
	cin >> n;

	vector<string> v;  // 단어 목록 저장
	string input;

	while (n--) {
		cin >> input;
		v.push_back(input);
	}

	cout << getDiffNum(v) << "\n";

	return 0;
}