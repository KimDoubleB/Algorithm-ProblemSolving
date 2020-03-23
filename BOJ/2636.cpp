#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int r, c;
int board[100][100];
bool check[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


//ġ����� ����
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

	//bfs�� �ٱ� ������ üũ
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

			//���� üũ
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

			//�湮 üũ
			if (check[nx][ny]) continue;

			//ġ���� ��� skip
			if (board[nx][ny] == 1) continue;

			q.push(make_pair(nx, ny));
			check[nx][ny] = true;;
		}
	}



	//�ٱ������� ����ִ� ġ��� ��´�.
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			//ġ�� �ƴѺκ� skip
			if (board[i][j] == 0) continue;


			//�����¿� �� �ϳ��� ���̶� ��������� ��´�.
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


		//ġ� �� ���� ������ �ݺ�
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
