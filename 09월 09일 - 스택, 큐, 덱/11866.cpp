#include <iostream>
#include <queue>

using namespace std;

void getJosephus(int n, int k) {
	queue<int> q;        // 앉은 상태 저장
	vector<int> order;   // 제거되는 사람의 번수를 차례대로 저장

	for (int i = 1; i <= n; i++) {   // 모든 사람 앉히기
		q.push(i);
	}

	while (!q.empty()) {
		int first, target;
		for (int i = 1; i < k; i++) {   // k번째 이전 사람들은 맨 뒤로 
			first = q.front();
			q.pop();
			q.push(first);
		}
		
		target = q.front();            // k번째 사람이 맨 앞에 오면 pop
		q.pop();
		order.push_back(target);
	}

	// 출력
	cout << "<";
	for (int i = 0; i < order.size() - 1; i++) {
		cout << order[i] << ", ";
	}
	cout << order.back() << ">" << "\n";

}


int main() {

	int n, k;        // 사람 수, 제거 기준 숫자
	cin >> n >> k;  

	getJosephus(n, k);

	return 0;
}