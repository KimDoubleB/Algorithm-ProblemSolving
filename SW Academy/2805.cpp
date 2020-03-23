#include <iostream>
#include <string>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main() {
	bb;
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case){
		int size, result = 0;
		cin >> size;
		int mid = size / 2;
		for (int i = 0; i < size; ++i) {
			string mat;
			cin >> mat;
			for (int j = i; j >= 0; --j) {
				if (j > mid) j = mid * 2 - j;
				if (j == 0) result += (mat[mid] - '0');
				else result += (mat[mid - j] - '0' + mat[mid + j] - '0');
			}
		}
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}