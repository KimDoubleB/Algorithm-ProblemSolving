#include <iostream>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, game[51][9], player[9];
bool already[9];
int maxres;

int start() {
	int res = 0, j = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0, g[4] = { 0, };
		while (true) {
			if (cnt >= 3) {
				res += g[3];
				break;
			}
			switch (game[i][player[j]]) {
			case 0:
				cnt++;
				break;
			case 1:
				g[3] += g[2];
				g[2] = g[1];
				g[1] = g[0];
				g[0] = 1;
				break;
			case 2:
				g[3] += (g[2] + g[1]);
				g[2] = g[0];
				g[1] = 1;
				g[0] = 0;
				break;
			case 3:
				g[3] += (g[2] + g[1] + g[0]);
				g[2] = 1;
				g[1] = g[0] = 0;
				break;
			case 4:
				g[3] += (g[2] + g[1] + g[0] + 1);
				g[2] = g[1] = g[0] = 0;
				break;
			}
			j = (j + 1) % 9;
		}

	}
	return res;
}

void selecting(int fix) {
	if (fix == 9 && player[3] == 0) {
		maxres = max(maxres, start());
		return;
	}

	for (int i = 0; i < 9; ++i) {
		if (already[i]) continue;
		player[fix] = i;
		already[i] = true;
		selecting(fix + 1);
		already[i] = false;
	}
}

int main() {
	bb;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> game[i][j];
	
	selecting(0);

	cout << maxres << '\n';
	
	return 0;
}