#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999
using namespace std;
int mat[101][101];
int visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int bridge(int x, int y, int ax, int ay) {
	return abs(x - ax) + abs(y - ay) - 1;
}
int main() {
	bb;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
		}
	}
	// dfs로 섬 개수, 섬 좌표 탐색
	stack<pair<int, int> > st;
	int island = 0;
	vector< vector< pair<int, int> > > gps; // 섬 좌표 저장
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 1) continue;
			if (mat[i][j] == 0) {
				visited[i][j] = 1;
				continue;
			}
			st.push({ i, j });
			++island;
			vector< pair <int, int> > tmp;
			while (!st.empty()) {
				pair<int, int> present = st.top();
				st.pop();
				visited[present.first][present.second] = 1;
				tmp.push_back({ present.first, present.second });
				for (int k = 0; k < 4; ++k) {
					int mx = dx[k] + present.first;
					int my = dy[k] + present.second;
					if (mx < 0 || my < 0 || mx >= N || my >= N) continue;
					if (visited[mx][my] == 1) continue;
					if (mat[mx][my] == 0) {
						visited[mx][my] = 1;
						continue;
					}
					st.push({ mx, my });
				}
			}
			gps.push_back(tmp);
		
		}
	}

	int bridge_len = INF;
	// island가 섬 개수를 가지고 있음.
	// 완전탐색을 통해 모든 거리 중 최소 거리 계산
	for (int i = 0; i < island; ++i) {
		for (int j = i+1; j < island; ++j) {
			vector<pair<int, int> > v1 = gps[i];
			vector<pair<int, int> > v2 = gps[j];
			for (int k1 = 0; k1 < v1.size(); ++k1) {
				for (int k2 = 0; k2 < v2.size(); ++k2) {
					bridge_len = min(bridge_len, bridge(v1[k1].first, v1[k1].second, v2[k2].first, v2[k2].second));
				}
			}
		}
	}

	cout << bridge_len << '\n';
	return 0;
}