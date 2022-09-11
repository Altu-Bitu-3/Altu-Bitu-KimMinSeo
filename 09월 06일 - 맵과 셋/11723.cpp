#include <iostream>
#include <vector>

using namespace std;

void calculate(vector<bool> &v, string action, int num) {
	if (action == "add" && v[num - 1] == false) v[num - 1] = true;

	if (action == "remove" && v[num - 1] == true) v[num - 1] = false;

	if (action == "check")
		v[num - 1] == true ? cout << 1 << "\n" : cout << 0 << "\n";

	if (action == "toggle") v[num - 1] = !v[num - 1];

	if (action == "all")
		for (int i = 0; i < 20; i++) v[i] = true;

	if (action == "empty")
		for (int i = 0; i < 20; i++) v[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;     // 연산개수
	cin >> m;   
	
	vector<bool> v;  // 집합에 포함되어 있는지 여부 저장
	v.assign(20, false);

	string action;
	int num;
	
	while (m--) {
		cin >> action;

		if (action != "all" && action != "empty") cin >> num;
		else num = 0;

		calculate(v, action, num);
		
	}

	return 0;
}