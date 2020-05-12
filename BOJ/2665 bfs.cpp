#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#define SIZE 51
using namespace std;

struct pt {
	int x, y;
};

queue<pt> q;
pt present;
int n, mincnt;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int m[SIZE][SIZE], visited[SIZE][SIZE];

void bfs() {
	for (int j = 0; j < SIZE; ++j) {
		memset(visited[j], -1, sizeof(int) * SIZE);
	}

	q.push({ 0, 0 });
	visited[0][0] = 0;
	while (!q.empty()) {
		present = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = present.x + dx[i];
			int y = present.y + dy[i];
			if (x >= n || y >= n || x < 0 || y < 0) continue;
			if (visited[x][y] != -1) {
				if (visited[present.x][present.y] >= visited[x][y]) continue;
			}

			q.push({ x, y });
			if (m[x][y]) visited[x][y] = visited[present.x][present.y];
			else visited[x][y] = visited[present.x][present.y] + 1;
		}
	}
}


int main() {
	cin >> n;
	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j) {
			m[i][j] = tmp[j] - '0';
		}
	}
	bfs();

	cout << visited[n - 1][n - 1] << '\n';
	return 0;
}

