#include <iostream>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int l[41][41], s[11][11], tmp[11][11]; // laptop size, sticker size
int n, m, k;
int r, c;

void rotate() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = s[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			s[i][j] = tmp[r - 1 - j][i];

	swap(r, c);
}
bool glue(int& px, int& py) {
	// check
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			if (px + x >= n || py + y >= m) return false;
			if (l[px + x][py + y] && s[x][y]) return false;
		}
	}
	
	// glue
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			if (s[x][y]) l[px + x][py + y] = 1;
		}
	}
	return true;
}

bool solution() {
	for (int rr = 0; rr < 4; ++rr) {
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < m; ++b) {
				if (l[a][b] && s[0][0]) continue;
				if (glue(a, b)) return true;
			}
		}
		rotate();
	}
	return false;
}

int main() {
	bb;
	cin >> n >> m >> k;
	int res = 0;
	for (int i = 0; i < k; ++i) {
		cin >> r >> c;
		// sticker input
		int size = 0;
		for (int a = 0; a < r; ++a) {
			for (int b = 0; b < c; ++b) {
				cin >> s[a][b];
				if (s[a][b]) ++size;
			}
		}

		if (solution())
			res += size;
	}
	cout << res << '\n';
	return 0;
}