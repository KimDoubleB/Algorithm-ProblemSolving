#include <iostream>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
int k, n;
ll line[10000];
ll minval = 1, maxval = 1;

void binarySearch() {
	ll num, mid, res = 0;

	while (maxval >= minval) {
		num = 0;
		mid = (minval + maxval) / 2;
		for (int i = 0; i < k; ++i)
			num += (line[i] / mid);
		
		if (num >= n) {
			res = max(res, mid);	// 마지막에 다른 정보가 들어갈 수 있으므로.
			minval = mid + 1;
		}
		else { 
			maxval = mid - 1; 
		}
	}
	cout << res << '\n';
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; ++i) {
		cin >> line[i];
		maxval = max(maxval, line[i]);
	}
	binarySearch();
}
