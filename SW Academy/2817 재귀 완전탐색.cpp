#include <iostream>
#include <vector>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int val[21], n, k, res;
void sum(int init, int index) {
	if (init == k) ++res;
	else if (index == n) return;
	else {
		sum(init, index + 1);
		init += val[index];
		sum(init, index + 1);
	}
}
int main() {
	bb;
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cin >> n >> k;
		res = 0;
		for (int i = 0; i < n; ++i) 
			cin >> val[i];
		sum(0, 0);
		cout << '#' << tt << ' ' << res << '\n';
	}
	return 0;
}