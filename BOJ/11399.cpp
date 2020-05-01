#include <iostream>
#include <algorithm>
#define SIZE 1001
using namespace std;
int n, m, p[SIZE], s;
int main() {
	// input
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	
	sort(p, p + n, less<int>());
	
	m = n;
	for (int i = 0; i < n; ++i, m--)
		s += (p[i] * m);

	cout << s << '\n';
	return 0;
}