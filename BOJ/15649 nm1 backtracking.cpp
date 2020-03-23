#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
bool isUsed[8];
int arr[8], n, m;
void nm(int k) {
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (isUsed[i]) continue;
			isUsed[i] = true;
			arr[k] = i + 1;
			nm(k + 1);
			isUsed[i] = false;
		}
	}
}
int main()
{
	bb;
	int k = 0;
	cin >> n >> m;
	nm(k);
	return 0;
}
