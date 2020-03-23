#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int r, c;
int board[100][100];
bool check[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


//치즈수를 센다
int countCheese() {
	int cnt = 0;
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			if (board[i][j] == 1) {
				cnt++;
			}
		}
	}

	return cnt;
}



void solve() {

	//bfs로 바깥 영역을 체크
	queue<pair<int, int>> q;
	memset(check, false, sizeof(check));
	int x = 0;
	int y = 0;

	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			//범위 체크
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

			//방문 체크
			if (check[nx][ny]) continue;

			//치즈인 경우 skip
			if (board[nx][ny] == 1) continue;

			q.push(make_pair(nx, ny));
			check[nx][ny] = true;;
		}
	}



	//바깥영역과 닿아있는 치즈는 녹는다.
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			//치즈 아닌부분 skip
			if (board[i][j] == 0) continue;


			//상하좌우 중 하나라도 밖이랑 닿아있으면 녹는다.
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (check[nx][ny]) {
					board[i][j] = 0;
					break;
				}
			}
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	int cheeseCnt = 0;
	int time = 0;
	int lastcnt = 0;
	while (true) {
		int tmp = countCheese();


		//치즈가 다 녹을 떄까지 반복
		if (tmp == 0) {
			break;
		}
		else {
			lastcnt = tmp;
		}

		solve();
		time++;
	}

	cout << time << '\n';
	cout << lastcnt << '\n';


	return 0;
}
