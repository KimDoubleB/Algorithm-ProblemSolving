#include <iostream>
#include <vector>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct point {
	int x, y;
};
vector<point> vec;
int m[11][11], colored[11][11];
int cpaper[6] = { 5, 5, 5, 5, 5, 5 }; // 하나 버림
int res = 26; // 최대 결과 25이므로, 그것보다 큰 값을 둔다

// 붙일 수 있는지 확인
bool check(int& x, int& y, int& bound) {
	for (int a = x; a < x + bound; ++a) {
		for (int b = y; b < y + bound; ++b) {
			if (a > 9 || b > 9) return false;	// 범위 오버
			if (colored[a][b]) return false;	// 이미 붙여졌으면, 붙일 수 없음
			if (!m[a][b]) return false;			// 붙일 수 없는 곳
		}
	}
	return true;
}

void glue(bool go, int& x, int& y, int& bound) {
	if (go) {
		// 붙이기
		for (int a = x; a < x + bound; ++a) {
			for (int b = y; b < y + bound; ++b) {
				colored[a][b] = 1;
			}
		}
		
	}
	else {
		// 제거하기
		for (int a = x; a < x + bound; ++a) {
			for (int b = y; b < y + bound; ++b) {
				colored[a][b] = 0;
			}
		}
	}
}

void solution(int num, int change) {
	if (vec.size() == change) { 
		// 다 붙인 경우
		res = min(res, num);
		return;
	}
	if (num >= res) return; // 현재 최소값보다 크면, 더 할 필요 없다.

	for (int i = 0; i < vec.size(); ++i) {
		point present = vec[i];
		if (colored[present.x][present.y]) continue;
		for (int j = 5; j > 0; --j) {
			if (cpaper[j] < 1) continue;
			if (check(present.x, present.y, j)) {
				// 색종이 붙이기
				glue(true, present.x, present.y, j);
				cpaper[j]--;
				
				// 재귀
				solution(num + 1, change + (j*j));

				// 색종이 제거
				glue(false, present.x, present.y, j);
				cpaper[j]++;
			}
		}
		/*
		여길 통과한다는 것은 이번 vec[i]에는 색종이를 붙이지 않는다는 것.
		즉, -1이 나올 수 밖에 없다. 그러니 종료.
		*/
		return; 

	}
}

int main() {
	bb;
	// input
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> m[i][j];
			if (m[i][j]) vec.push_back({ i, j });
		}
	}

	solution(0, 0);

	if (res > 25) cout << -1 << '\n';
	else cout << res << '\n';


	return 0;
}