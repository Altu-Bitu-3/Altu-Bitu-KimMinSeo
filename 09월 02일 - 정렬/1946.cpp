#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getPassNum(vector<int> &grades) {
	int count = 0;


	return count;
}

int main() {

	int n;    // 테스트 케이스 수
	cin >> n;

	vector<int> result(n, 1);  // 서류 1등은 무조건 선발되므로 넣어놓고 시작


	int num;    // 각 테스트 케이스별 지원자 수

	for (int i = 0; i < n; i++) {
		vector<pair<int,int>> grade;  //  서류등수, 면접등수 벡터
		
		cin >> num;

		for (int j = 0; j < num; j++) {

			// 서류등수, 면접등수
			int g1, g2;       
			cin >> g1 >> g2;
			
			grade.push_back({ g1, g2 });
		}

		sort(grade.begin(), grade.end());     // 서류등수 순으로 정렬
		int maxg1_g2 = grade[0].second;       // 서류 1등의 면접등수


		for (int k = 1; k < num; k++) {           // 현재 maxg1_g2보다 서류가 더 낮은 지원자 중에서 
			if (grade[k].second < maxg1_g2) {     // 면접이라도 더 높으면 선발됨 
				result[i]++;
				maxg1_g2 = grade[k].second;    
			}
			
		}
	}


	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}