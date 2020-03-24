#include <iostream>
#include <algorithm>
#include <vector>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, g, r;
int res = 0, flower = 0;
int permu[11], garden[51][51], garden2[51][51], isNow[51][51];
int soil, ind, new_x, new_y;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> point;
pair<int, int> present;
void spread(vector< pair<int, int>>& li, bool isRed) {
	vector< pair<int, int>> new_li;
	for (int i = 0; i < li.size(); ++i) {
		present = li[i];
		if (garden2[present.first][present.second] == 5) // 꽃이 된 자리인 경우
			continue;
		for (int j = 0; j < 4; ++j) {
			new_x = present.first + dx[j];
			new_y = present.second + dy[j];
			// 합법한 범위인가?
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
				continue;

			// 호수, 빨강, 꽃인가?
			if (garden2[new_x][new_y] == 0 ||
				garden2[new_x][new_y] == 4 ||
				garden2[new_x][new_y] == 5)
				continue;

			// 빨강 spread인가?
			if (isRed) {
				// Red
				if (garden2[new_x][new_y] == 3) { // 이미 초록 배양액 자리이면,
					if (isNow[new_x][new_y]) { // 이번 차례에 퍼진 초록 배양액인가?
						garden2[new_x][new_y] = 5; // flower
						flower++;
					}
					continue;
				}
				garden2[new_x][new_y] = 4;
				new_li.push_back({ new_x, new_y });
			}
			else {
				// Green
				// 이미 초록 배양액 자리인가?
				if (garden2[new_x][new_y] == 3) continue;
				garden2[new_x][new_y] = 3;
				isNow[new_x][new_y] = 1;
				new_li.push_back({ new_x, new_y });
			}
		}
	}
	li = new_li; // 새롭게 vector 업데이트
}
int main() {
	bb;

	// input
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> garden[i][j];
			if (garden[i][j] == 2) {
				soil++;
				point.push_back({ i, j });
			}
		}
	}

	// for permutation
	for (int i = 0; i < g; ++i) {
		permu[ind] = 2;
		++ind;
	}
	for (int i = 0; i < r; ++i) {
		permu[ind] = 1;
		++ind;
	}

	
	do {
		
		copy(&garden[0][0], &garden[0][0] + 51 * 51, &garden2[0][0]);
		
		flower = 0;
		vector< pair <int, int> > red, green;
		for (int i = 0; i < soil; ++i) {
			if (permu[i] == 2) { // green
				green.push_back(point[i]);
				garden2[point[i].first][point[i].second] = 3;
			}
			else if (permu[i] == 1) { // red
				red.push_back(point[i]);
				garden2[point[i].first][point[i].second] = 4;
			}
		}

		// solution
		while (true) {
			spread(green, false);
			spread(red, true);
			
			if (green.size() == 0 && red.size() == 0)
				break;

			for (int i = 0; i < green.size(); ++i)
				isNow[green[i].first][green[i].second] = 0;
	
		}

		res = max(flower, res);
	} while (prev_permutation(permu, permu + soil));

	cout << res << '\n';
	return 0;
}