#include <iostream>
#define SIZE 11
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans, cnt, start = 100;
bool broken[10];

int moveRemote(int num) {
	// 0인 경우, 따로 잡아준다.
	if (num == 0) {
		if (broken[num]) return -1;
		return 1;
	}

	// 숫자로 이동이 가능한가?
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

	// 가고자 하는 채널과 현재 채널이 같으면 그냥 종료
	if (n == start) {
		cout << 0 << '\n';
		return 0;
	}

	// Process
	ans = abs(n - start);	// +/-로만 이동하는 경우
	for (int i = 0; i < 1'000'000; ++i) {
		cnt = moveRemote(i);	// 숫자버튼으로 가능한가?
		if (cnt > 0) {			// 숫자버튼으로 이동가능하면
			cnt += abs(n - i);	// 숫자버튼으로 이동하고, +/- 이동
			ans = ans > cnt ? cnt : ans;	// 값이 더 작으면, 업데이트
		}
	}

	cout << ans << '\n';
	return 0;
}