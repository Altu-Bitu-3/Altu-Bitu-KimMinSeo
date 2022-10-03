#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 10;

int cost[SIZE][SIZE];            // 비용 행렬
bool check[SIZE] = { false };    // 경로에 이미 사용된 도시인지 체크
int n;                           // 도시 개수
int minCost = 2147483647;        // 최소비용, int 최대값으로 초기화


// start: 시작 도시 인덱스, current: 최근 방문 도시 인덱스, cost_current: 쌓인 비용, count : 지금까지 경로에 사용된 도시 개수
void backTracking(int start, int current, int cost_current, int count) { 

	// case 1) n개 도시로 여행 경로 완성한 경우
	if (count == n) {

		// 출발지로 돌아오는 길 있는 경우
		if (cost[current][start] > 0)   minCost = min(minCost, cost_current + cost[current][start]);

		return;
	}

	// case 2) 경로 탐색
	for (int i = 0; i < n; i++) {

		// 방문조건 : (1) 방문한 적 X,  (2) 직전 도시와 이어져 있음
		if (!check[i] && cost[current][i] > 0) { 
			check[i] = true;
			backTracking(start, i , cost_current + cost[current][i], count + 1);  

			check[i] = false;
		}
	}
}


int main() {

	cin >> n;  // 도시의 수

	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}


	for (int i = 0; i < n; i++) {      
		check[i] = true;             
		backTracking(i, i, 0, 1);    // 출발지 도시는 방문하며 시작하므로 count = 1부터 시작
		check[i] = false; 
	}
	
	cout << minCost << "\n";

	return 0;
}