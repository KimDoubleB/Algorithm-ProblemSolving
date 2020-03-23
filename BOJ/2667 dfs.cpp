#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int n, map[26][26];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool isVisited[26][26];
bool isPossible(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	return true;
}
int main()
{
	bb;
	cin >> n;
	string tmp;
	// input
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for(int j = 0; j < n; ++j) map[i][j] = tmp[j] - '0';
	}
	vector<int> all_danji;
	stack< pair<int, int> > st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isVisited[i][j] || map[i][j] == 0) continue; // �ʿ� ���� �� �پ�ѱ�
			// ���⿡ ������ ���ο� ���� �ǹ�
			int house = 0;
			st.push({ i, j }); // ù ������ �ֱ�
			while (!st.empty()) {
				pair<int, int> present = st.top();
				st.pop();
				if (isVisited[present.first][present.second]) continue;
				++house;
				isVisited[present.first][present.second] = true;

				for (int k = 0; k < 4; ++k) { // �����¿� ��ȸ
					int nx = present.first + dx[k], ny = present.second + dy[k];
					if (isPossible(nx, ny) && !isVisited[nx][ny] && map[nx][ny] == 1 ) {
						st.push({ nx, ny });
					}
				}

			}	
			all_danji.push_back(house);
		}
	}

	// ��� ���
	// ���� ������ - ���� ���� �� ���� ��� ���(��������)
	int num_danji = all_danji.size();
	cout << num_danji << '\n';
	sort(all_danji.begin(), all_danji.end());
	for (int i = 0; i < num_danji; ++i)
		cout << all_danji[i] << '\n';
	return 0;
}
