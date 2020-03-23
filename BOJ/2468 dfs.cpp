#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int m[101][101];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
bool isVisited[101][101];
int main() {
	bb;
	int n, pmin = 101, pmax = 0;
	int all_max = 1; // �� �ȿ��� ������ �������� ���� ���� 1�̹Ƿ�, �������� �ִ��������� �ּҰ��� 1�̴�.
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
			pmin = min(pmin, m[i][j]);
			pmax = max(pmax, m[i][j]);
		}
	}
	for (int k = pmin; k < pmax; ++k) {

		for (int i = 0; i < 101; i++) { // memset�� ���, cstring header ����
			memset(isVisited[i], false, sizeof(isVisited[i]));
		}

		int res = 0;
		stack<pair <int, int> > st;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (isVisited[i][j] || m[i][j] <= k) continue;
				++res;
				st.push({ i, j });
				isVisited[i][j] = true;

				// dfs
				while (!st.empty()) {
					int top_x = st.top().first, top_y = st.top().second;
					st.pop();
					for (int z = 0; z < 4; ++z) {
						int nx = top_x + dx[z], ny = top_y + dy[z];
						if (nx < 0 || nx >= n
							|| ny < 0 || ny >= n)
							continue;
						if (isVisited[nx][ny] || m[nx][ny] <= k) continue;
						st.push({ nx, ny });
						isVisited[nx][ny] = true;
					}
				}
			}
		}
		all_max = max(all_max, res);
	}
	cout << all_max << '\n';

	return 0;
}