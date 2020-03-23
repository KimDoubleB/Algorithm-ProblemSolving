#include <iostream>
#include <stack>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);
using namespace std;
/*
�� �ڵ�� �ſ� ������.
������ �����Ǵ� ��ȸ�̹Ƿ� ��� stack�� �Ⱦ��� vector ����ϸ鼭 ��� ���鿡 ���� ������ �س��� �����ϴ°� �� ���ϰ� �̻� �� ����.
���̵� �� ��.
*/

struct ptval {
	int x, y, cnt;
};
ptval present;
bool isvisited[20][20][4]; // �̰� ���� ū ���̵��
/*
	�����̶� ���⼺�� �߽õǴ� ��.
	6���� ������ �������ִ� ���� �����ϱ� ����. ������ ��ȸ�ϸ鼭 6���� 1���� ������ 5���� �̾ �������� �ν��ϸ� �ȵȴ�.
	�׷��� ó�� 6���� ������ �������ִ� ���� �ν����� ��, isvisited�� ��ŷ�ϸ� �Ǵµ� �ܼ��� ���⼺ ���� ��ŷ�ϰ� �Ǹ�,
	�� ������ �ƴ� �ٸ� ���⿡�� ������ �־ �����ع����� �ȴ�.
	��, ���⿡ ���� ���� isvisited�� �־������ν�, Ư�� ���������� visited�� ��ŷ�Ǿ� ������ �����ϴ� ������ ����ȴ�.
*/
int m[20][20], new_x, new_y, ans_x, ans_y;
int dx[8] = { 1, 0, 1, 1};
int dy[8] = { 0, 1, 1, -1};
bool leftPoint(int& nx, int& ny) {
	if (ans_y > ny)
		return true;
	else if (ans_y == ny)
		if (ans_x > nx)
			return true;
	return false;
}
bool solution(int& x, int& y, int& target) {
	stack<ptval> st;

	for (int k = 0; k < 4; ++k) {
		ans_x = x;
		ans_y = y;
		new_x = dx[k] + x;
		new_y = dy[k] + y;
		if (new_x < 0 || new_x > 18 || new_y < 0 || new_y > 18) continue;
		if (isvisited[new_x][new_y][k]) continue;
		if (m[new_x][new_y] == target) {
			st.push({ new_x, new_y, 2 });
			isvisited[new_x][new_y][k] = true;
			int maxcnt = 0;
			while (!st.empty()) {
				present = st.top(); st.pop();
				
				if (leftPoint(present.x, present.y)) {
					ans_x = present.x;
					ans_y = present.y;
				}
				maxcnt = present.cnt;
				
				new_x = dx[k] + present.x;
				new_y = dy[k] + present.y;
				if (new_x < 0 || new_x > 18 || new_y < 0 || new_y > 18) break;
				if (isvisited[new_x][new_y][k]) continue;
				if (m[new_x][new_y] == target) {
					st.push({ new_x, new_y, present.cnt + 1 });
					isvisited[new_x][new_y][k] = true;
				}
			}
			if (maxcnt == 5) {
				cout << target << '\n';
				cout << ans_x + 1 << ' ' << ans_y + 1 << '\n';
				return true;
			}
		}
	}
	return false;
}
int main() {
	bb;
	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			cin >> m[i][j];
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (m[i][j] == 1 || m[i][j] == 2)
				if (solution(i, j, m[i][j]))
					return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}