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

	queue< tuple<int, int, int> > q; // tuple ���
	// tuple�� [ get<����> ������ ] ������ �����͸� ������ �� �ִ�.
	tuple<int, int, int> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 1) {
				q.push(make_tuple(i, j, 0)); // ���� �丶���� ��ġ ���� (����° �����ʹ� �ð� �ǹ�)
				isVisited[i][j] = true;
			}
			else if (map[i][j] == 0) { 
				// �� �����־� �Ұ����� ���� ������ �丶�䰡 �������� ��츸 �ش��ϹǷ� 
				int tmp1 = 0, tmp2 = 0;
				for (int k = 0; k < 4; ++k) { // �����¿� ��ȸ
					int nx = i + dx[k], ny = j + dy[k];
					// ��ȭ�¿찡 -1�� �����ִ��� (�丶�䰡 ����ִ���) Ȯ��
					if (isPossible(nx, ny)) {
						++tmp1;
						if (map[nx][ny] == -1)
							++tmp2;
					}
				}
				if (tmp1 == tmp2){
					// �����¿�� �����־�, ���������� �� ���� �� ���� ��� �ٷ� '�Ұ���' ��� �� ����
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}

	// bfs --> �ּ� �ð��̹Ƿ� ������ ���� �ּҽð��� �˰��� ������, bfs�� ���
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) { // �����¿� ��ȸ
			int nx = get<0>(t) + dx[k], ny = get<1>(t) + dy[k];
			if (isPossible(nx, ny) && !isVisited[nx][ny] && map[nx][ny] != -1) { 
				// �ش� ���ǿ� �����Ѵٴ� ���� map[nx][ny]=0 �� �������� �ǹ� (������ �丶��)
				// --> ��� bfs�� �־������ν� ���� �丶��� ��ȯ������ �ǹ� --> tuple�� ����° ���� �ð��� ���� ����.
				isVisited[nx][ny] = true; // bfs �������� ��ü������ �������� ��ĥ �� �ֱ� ������, �� visited ����� ��.
				q.push(make_tuple(nx, ny, get<2>(t) + 1));
			}
		}
	}

	// ������ bfs ������ ��, �ش� tuple�� �ð��� �������� �� �����µ� �ּҽð��� �� �� ����.
	cout << get<2>(t) << '\n';
	return 0;
}