#include <iostream>
#include <vector>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct point {
	int x, y;
};
vector<point> vec;
int m[11][11], colored[11][11];
int cpaper[6] = { 5, 5, 5, 5, 5, 5 }; // �ϳ� ����
int res = 26; // �ִ� ��� 25�̹Ƿ�, �װͺ��� ū ���� �д�

// ���� �� �ִ��� Ȯ��
bool check(int& x, int& y, int& bound) {
	for (int a = x; a < x + bound; ++a) {
		for (int b = y; b < y + bound; ++b) {
			if (a > 9 || b > 9) return false;	// ���� ����
			if (colored[a][b]) return false;	// �̹� �ٿ�������, ���� �� ����
			if (!m[a][b]) return false;			// ���� �� ���� ��
		}
	}
	return true;
}

void glue(bool go, int& x, int& y, int& bound) {
	if (go) {
		// ���̱�
		for (int a = x; a < x + bound; ++a) {
			for (int b = y; b < y + bound; ++b) {
				colored[a][b] = 1;
			}
		}
		
	}
	else {
		// �����ϱ�
		for (int a = x; a < x + bound; ++a) {
			for (int b = y; b < y + bound; ++b) {
				colored[a][b] = 0;
			}
		}
	}
}

void solution(int num, int change) {
	if (vec.size() == change) { 
		// �� ���� ���
		res = min(res, num);
		return;
	}
	if (num >= res) return; // ���� �ּҰ����� ũ��, �� �� �ʿ� ����.

	for (int i = 0; i < vec.size(); ++i) {
		point present = vec[i];
		if (colored[present.x][present.y]) continue;
		for (int j = 5; j > 0; --j) {
			if (cpaper[j] < 1) continue;
			if (check(present.x, present.y, j)) {
				// ������ ���̱�
				glue(true, present.x, present.y, j);
				cpaper[j]--;
				
				// ���
				solution(num + 1, change + (j*j));

				// ������ ����
				glue(false, present.x, present.y, j);
				cpaper[j]++;
			}
		}
		/*
		���� ����Ѵٴ� ���� �̹� vec[i]���� �����̸� ������ �ʴ´ٴ� ��.
		��, -1�� ���� �� �ۿ� ����. �׷��� ����.
		*/
		return; 

	}
}

int main() {
	bb;
	// input
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> m[i][j];
			if (m[i][j]) vec.push_back({ i, j });
		}
	}

	solution(0, 0);

	if (res > 25) cout << -1 << '\n';
	else cout << res << '\n';


	return 0;
}