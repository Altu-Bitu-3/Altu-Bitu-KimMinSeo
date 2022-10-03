#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num;              // 입력받은 숫자 목록 (중복 가능)
vector<bool> check(SIZE);     // 수열에 사용한 적 있 숫자인지 여부
vector<int> result(SIZE);     // 수열 만드는 벡터


void backTracking(int len) {   // len : 지금까지 만든 수열의 길이
	if (len == m) {
		for(int i= 0; i< m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 수열 만들기
	int before = -1;   // 바로 이전에 선택한 값 저장 
	for (int i = 0; i < num.size(); i++) {
		if (!check[i] && num[i] != before) {
			result[len] = num[i];
			check[i] = true;
			before = num[i];            // before 갱신
			backTracking(len + 1);

			check[i] = false;
		}
	}
}

int main() {

	cin >> n >> m;   // m : 수열 길이

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}
	
	sort(num.begin(), num.end());  // 사전순으로 증가하는 수열 만들기 위해 크기 순 정렬
	backTracking(0);

	return 0;
}