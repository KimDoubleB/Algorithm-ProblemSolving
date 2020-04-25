#include <iostream>
#define SIZE 11
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans, cnt, start = 100;
bool broken[10];

int moveRemote(int num) {
	// 0�� ���, ���� ����ش�.
	if (num == 0) {
		if (broken[num]) return -1;
		return 1;
	}

	// ���ڷ� �̵��� �����Ѱ�?
	int len = 0;
	while (num > 0) {
		if (broken[num % 10]) return -1;
		len++;
		num /= 10;
	}
	return len;
}

int main() {
	// input
	int tmp;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		broken[tmp] = true;
	}

	// ������ �ϴ� ä�ΰ� ���� ä���� ������ �׳� ����
	if (n == start) {
		cout << 0 << '\n';
		return 0;
	}

	// Process
	ans = abs(n - start);	// +/-�θ� �̵��ϴ� ���
	for (int i = 0; i < 1'000'000; ++i) {
		cnt = moveRemote(i);	// ���ڹ�ư���� �����Ѱ�?
		if (cnt > 0) {			// ���ڹ�ư���� �̵������ϸ�
			cnt += abs(n - i);	// ���ڹ�ư���� �̵��ϰ�, +/- �̵�
			ans = ans > cnt ? cnt : ans;	// ���� �� ������, ������Ʈ
		}
	}

	cout << ans << '\n';
	return 0;
}