#include <iostream>
#include <stack>
using namespace std;
struct pipe {
	int x, y, status;
};
stack<pipe> st;
pipe present;
int dx[3] = { 0, 1, 1 }, dy[3] = { 1, 0, 1 };
int n, m[17][17], new_x, new_y;
bool possible(int& x, int& y, int& direction) {
	// Map ���� ������ Ȯ��
	if (x < 0 || y < 0 || x >= n || y >= n) 
		return false;
	
	// �� ����
	if (direction == 0 || direction == 1) // ����, ����
	{
		if (m[x][y])
			return false;
	}
	else {
		if (m[x][y] || m[x - 1][y] || m[x][y - 1]) // �밢��
			return false;
	}
	return true;
}
void move(int direction) {
	// direction: ���� - 0, ���� - 1, �밢�� - 2
	new_x = present.x + dx[direction];
	new_y = present.y + dy[direction];
	if (possible(new_x, new_y, direction))
		st.push({ new_x, new_y, direction });
}

void solution(int& cnt) {
	st.push({ 0, 1, 0 });
	while (!st.empty()) {
		present = st.top(); st.pop();
		if (present.x == n - 1 && present.y == n - 1) {
			cnt++;
			continue;
		}

		switch (present.status) {
		case 0: // ����
			move(0);
			move(2);
			break;
		case 1: // ����
			move(1);
			move(2);
			break;
		default: // �밢��
			move(0);
			move(1);
			move(2);
			break;
		}
	}
}

int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i][j];
	solution(cnt);
	cout << cnt << '\n';
	return 0;
}