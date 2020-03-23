#include <iostream>
#include <stack>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);
using namespace std;
/*
이 코드는 매우 더럽다.
방향이 고정되는 순회이므로 사실 stack을 안쓰고 vector 사용하면서 모든 점들에 대해 저장을 해놓고 연산하는게 더 편하고 이쁠 것 같다.
아이디어만 볼 것.
*/

struct ptval {
	int x, y, cnt;
};
ptval present;
bool isvisited[20][20][4]; // 이게 제일 큰 아이디어
/*
	오목이란 방향성이 중시되는 것.
	6개가 나란히 놓여져있는 것은 무시하기 쉽다. 하지만 순회하면서 6개중 1개를 제외한 5개를 이어서 오목으로 인식하면 안된다.
	그러면 처음 6개를 나란히 놓여져있는 것을 인식했을 때, isvisited로 마킹하면 되는데 단순히 방향성 없이 마킹하게 되면,
	그 방향이 아닌 다른 방향에서 오목이 있어도 무시해버리게 된다.
	즉, 방향에 대한 값을 isvisited에 넣어줌으로써, 특정 방향으로의 visited가 마킹되어 있으면 무시하는 식으로 진행된다.
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