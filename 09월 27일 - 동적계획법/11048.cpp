#include <iostream>
#include <vector>

using namespace std;


int maxCandy(vector<vector<int>> &v, vector<vector<int>>& dp, int n, int m) {
	int resultMaxCandy = 0;                                // 최종 사탕 개수

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = v[i][j] + max(dp[i - 1][j], dp[i][j - 1]);   // 어차피 대각선은 가지 않는 것이 이동 많이 할 수 있으므로 max
		}
	}

	return dp[n][m];
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n+1, vector<int>(m+1, 0));       // 놓여져 있는 사탕 개수
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // 해당 좌표까지 오는데 가져올 수 있는 최대 사탕 개수

	int input;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			v[i][j] = dp[i][j] = input;
		}
	}

	cout << maxCandy(v, dp, n, m) << "\n";

	return 0;
}