#include <iostream>
#include <set>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int m[52][52], tmp[52][52];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int r, c, t, air_x, air_y;

bool isPossible(int& x, int& y) {
	if (x < 0 || y < 0 || x >= r || y >= c) return false;
	if ((air_x == x && air_y == y) || (air_x - 1 == x && air_y == y)) return false;
	return true;
}

void spread() {
	set<pair <int, int>> s2;

	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			if (m[x][y] > 0) {
				int dust_remainder = m[x][y] / 5;
				int res = 0;
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (isPossible(nx, ny)) {
						s2.insert({ nx, ny }); // new dust space
						tmp[nx][ny] += dust_remainder;
						++res;
					}
				}
				// update
				m[x][y] -= (dust_remainder * res);
			}
		}
	}

	// °ª ÃÖÁ¾ update
	for (set<pair <int, int>>::iterator iter = s2.begin(); iter != s2.end(); ++iter) {
		pair<int, int> present = *iter;
		m[present.first][present.second] += tmp[present.first][present.second];
		tmp[present.first][present.second] = 0;
	}
}
int main()
{
	bb;
	cin >> r >> c >> t;
	int i;
	for (i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> m[i][j];
			if (m[i][j] < 0) {
				air_x = i, air_y = j;
			}
		}
	}

	for (int tt = 0; tt < t; ++tt) {
		spread();

		// air_x -1 , air_y
		int swap_place = 0;
		for (i = air_y + 1; i < c; ++i)
			swap(m[air_x - 1][i], swap_place);
		for (i = air_x - 2; i >= 0; --i)
			swap(m[i][c - 1], swap_place);
		for (i = c - 2; i >= air_y; --i)
			swap(m[0][i], swap_place);
		for (i = 1; i < air_x - 1; ++i)
			swap(m[i][air_y], swap_place);

		// air_x , air_y
		swap_place = 0;
		for (i = air_y + 1; i < c; ++i)
			swap(m[air_x][i], swap_place);
		for (i = air_x + 1; i < r; ++i)
			swap(m[i][c - 1], swap_place);
		for (i = c - 2; i >= air_y; --i)
			swap(m[r - 1][i], swap_place);
		for (i = r - 2; i > air_x; --i)
			swap(m[i][air_y], swap_place);
	}

	int res = 0;
	for (i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) 
			if (m[i][j] > 0) res += m[i][j];
		
	cout << res << '\n';
	return 0;
}
