#include <iostream>
#include <queue>
#include <tuple>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
bool isVisited[1002][1002];
int map[1002][1002], m, n;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool isPossible(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}
int main()
{
	bb;
	int num_tomato = 0;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> map[i][j];

	queue< tuple<int, int, int> > q; // tuple 사용
	// tuple은 [ get<순서> 변수명 ] 식으로 데이터를 가져올 수 있다.
	tuple<int, int, int> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 1) {
				q.push(make_tuple(i, j, 0)); // 익은 토마토의 위치 저장 (세번째 데이터는 시간 의미)
				isVisited[i][j] = true;
			}
			else if (map[i][j] == 0) { 
				// 다 막혀있어 불가능할 경우는 안익은 토마토가 막혀있을 경우만 해당하므로 
				int tmp1 = 0, tmp2 = 0;
				for (int k = 0; k < 4; ++k) { // 상하좌우 순회
					int nx = i + dx[k], ny = j + dy[k];
					// 상화좌우가 -1로 막혀있는지 (토마토가 비어있는지) 확인
					if (isPossible(nx, ny)) {
						++tmp1;
						if (map[nx][ny] == -1)
							++tmp2;
					}
				}
				if (tmp1 == tmp2){
					// 상하좌우로 막혀있어, 절대적으로 다 익을 수 없는 경우 바로 '불가능' 출력 및 종료
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}

	// bfs --> 최소 시간이므로 퍼져갈 때의 최소시간을 알고자 함으로, bfs를 사용
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) { // 상하좌우 순회
			int nx = get<0>(t) + dx[k], ny = get<1>(t) + dy[k];
			if (isPossible(nx, ny) && !isVisited[nx][ny] && map[nx][ny] != -1) { 
				// 해당 조건에 만족한다는 것은 map[nx][ny]=0 인 상태임을 의미 (안익은 토마토)
				// --> 고로 bfs에 넣어줌으로써 익은 토마토로 변환됬음을 의미 --> tuple의 세번째 값인 시간을 증가 해줌.
				isVisited[nx][ny] = true; // bfs 형식으로 전체적으로 퍼져가며 겹칠 수 있기 때문에, 꼭 visited 해줘야 함.
				q.push(make_tuple(nx, ny, get<2>(t) + 1));
			}
		}
	}

	// 마지막 bfs 돌았을 때, 해당 tuple의 시간을 가져오면 다 퍼지는데 최소시간을 알 수 있음.
	cout << get<2>(t) << '\n';
	return 0;
}