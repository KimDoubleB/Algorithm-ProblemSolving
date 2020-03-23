#include <iostream>
#include <queue>
#include <string>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
#define SIZE 1001
using namespace std;
struct gps {
	int x, y, cnt;
	bool use;
};
int map[SIZE][SIZE];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool visited[SIZE][SIZE][2];
int n, m, i, j, new_x, new_y, cnt;
bool use_temp;
queue<gps> q;
gps igps;
void bfs() {
	igps = { 0, 0, 1, false };
	q.push(igps);
	visited[0][0][0] = true;

	while (!q.empty()) {
		igps = q.front(); q.pop();
		cnt = igps.cnt;
		use_temp = igps.use;

		if (igps.x == (n - 1) && igps.y == (m - 1)){
			cout << cnt << '\n';
			return;
		}
		
		// ���� �μ̴� ���, �Ⱥμ̴� ��� �Ѵ�.
		for (i = 0; i < 4; ++i) {
			new_x = igps.x + dx[i];
			new_y = igps.y + dy[i];
			if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;
			if (visited[new_x][new_y][use_temp] || map[new_x][new_y] == 1) continue;
			q.push({ new_x, new_y, cnt+1, use_temp });
			visited[new_x][new_y][use_temp] = true; // �̰� �������ν� �Ʒ� ���� �Ⱥν� ��쿡�� �� ���� �ٽ� �鸮�� �ʴ´�.
		}
		
		// ���� �Ⱥμ̴� ��츸.
		if (use_temp == 0) {
			// ������ ��ȸ�� ���� ���� ���ǿ� ����������, ������ visited ǥ�⸦ �صξ��⿡ ��ȸ���� �ʴ´�.
			for (i = 0; i < 4; ++i) {
				new_x = igps.x + dx[i];
				new_y = igps.y + dy[i];
				if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;
				if (visited[new_x][new_y][use_temp]) continue;

				q.push({ new_x, new_y, cnt+1, !use_temp });
				visited[new_x][new_y][use_temp + 1] = true;
			}
		}
	}
	cout << -1 << '\n';

}
int main()
{
	bb;
	string str;
	cin >> n >> m;
	// input
	for (i = 0; i < n; ++i) {
		cin >> str;
		for (j = 0; j < m; ++j)
			map[i][j] = str[j] - '0';
	}

	bfs();

	return 0;
}
