#include <iostream>
#include <stack>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);
using namespace std;
int dice[10001][6], n, nmax;
int reverse(int& now) {
	switch (now) {
	case 0:
		return 5;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 0;
	}
}

void diceStack(int beforeTop, int order) {
	if (order > n) return;
	int under = 0, top = 0, maxval = 0;

	// ¾Æ·§¸é, À­¸é ÁöÁ¤
	for (int k = 0; k < 6; ++k) {
		if (beforeTop == dice[order][k]) {
			under = k;
			top = reverse(under);
			break;
		}
	}

	// ¿·¸é ÃÖ´ë°ª
	for (int k = 0; k < 6; ++k) {
		if (k == under || k == top) continue;
		maxval = max(maxval, dice[order][k]);
	}
	nmax += maxval;

	return diceStack(dice[order][top], order + 1);
}


int main() {
	bb;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j)
			cin >> dice[i][j];
	int res = 0;
	for (int i = 1; i < 7; ++i) {
		nmax = 0;
		diceStack(i, 0);
		res = max(res, nmax);
	}
	cout << res << '\n';
	return 0;
}