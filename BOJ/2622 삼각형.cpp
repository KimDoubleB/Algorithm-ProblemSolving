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
			if (c < b) break; // c�� ���� ū ������ ����
			// �ﰢ�� ��Ģ --> ���� ū ���� ������ �κ��� �պ��� �۾ƾ� �Ѵ�.
			if (c < a + b) cnt++; 
		}
	}
	cout << cnt << '\n';

}
