#include <iostream>
#include <algorithm>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int arr[8], n, m;
bool isUsed[8];
void nm(vector<int>& vec, int min, int k) {
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = min; i < n; ++i) {
			if (isUsed[i]) continue;
			isUsed[i] = true;
			arr[k] = vec[i];
			nm(vec, i, k + 1);
			isUsed[i] = false;
		}
	}
}
int main()
{
	bb;
	int k = 0;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	nm(vec, 0, k);
	return 0;
}
