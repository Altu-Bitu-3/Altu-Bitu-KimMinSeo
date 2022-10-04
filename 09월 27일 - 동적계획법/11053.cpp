#include <iostream>  // 입출력 헤더
#include <vector>    // 벡터 헤더
#include <algorithm> // 알고리즘 헤더

using namespace std;  // std 라이브러리

// 시간 복잡도 O(n^2)
int solution(int n, vector<int>& arr) {
    vector<int> dp(n, 1);    // 해당 수열 원소까지의 부분 수열 원소 개수
    int ans = 1;             // 최장 길이

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            // 증가하는 관계라면
            if (arr[i] > arr[j]) {             
                dp[i] = max(dp[i], dp[j] + 1);  // dp 갱신
            }
        }
        ans = max(ans, dp[i]); // 최장 길이 갱신
    }
    return ans;
}

int main() {
    int n;     // 수열의 크기
    cin >> n;

    vector<int> arr(n, 0);  // 수열

    for (int i = 0; i < n; i++) {
        cin >> arr[i];              // 수열 초기화
    }

    // 연산 & 출력
    cout << solution(n, arr);
}