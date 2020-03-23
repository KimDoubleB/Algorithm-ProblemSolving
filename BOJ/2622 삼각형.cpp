#include <iostream>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
	bb;
	int n, a, b, c, cnt=0;
	cin >> n;
	// a <= b <= c
	for (a = 1; a < n - 1; ++a) {
		for (b = a; b < n - 1 - a; ++b) {
			c = n - b - a;
			if (c < b) break; // c가 가장 큰 변으로 고정
			// 삼각형 법칙 --> 가장 큰 변이 나머지 두변의 합보다 작아야 한다.
			if (c < a + b) cnt++; 
		}
	}
	cout << cnt << '\n';

}
