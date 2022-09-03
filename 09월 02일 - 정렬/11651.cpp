#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Point {
	int x, y;
};

bool cmp(const Point& a, const Point& b) {

	if (a.y != b.y) return a.y < b.y;
	if (a.x != b.x) return a.x < b.x;
	
}


int main() {

	int n; 
	cin >> n;
	vector<Point> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), cmp);


	for (int i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}