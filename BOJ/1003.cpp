#include <iostream>
#define SIZE 41
using namespace std;
int t, n, fi[2][SIZE] = { {1, 0,}, {0, 1,} };
int main() {

	// Calculate all
	for (int i = 2; i < SIZE; ++i) {
		fi[0][i] = fi[0][i - 1] + fi[0][i - 2];
		fi[1][i] = fi[1][i - 1] + fi[1][i - 2];
	}
	
	// input & print
	cin >> t;
	while (t--) {
		cin >> n;
		cout << fi[0][n] << ' ' << fi[1][n] << '\n';
	}

	return 0;
}