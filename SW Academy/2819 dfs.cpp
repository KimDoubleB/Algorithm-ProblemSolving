#include <iostream>
#include <string.h>
#include <stack>
#include <set>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct point {
	int x, y;
	string num;
};
char m[4][4];
string tmp = "";
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int new_x, new_y;
void solution(int& i, int& j, set<string>& numset) {
	stack<point> st;
	point present;
	st.push({ i, j, tmp + m[i][j] });
	while (!st.empty()) {
		present = st.top();
		st.pop();
		if (present.num.size() == 7) {
			numset.insert(present.num);
			continue;
		}
		for (int k = 0; k < 4; ++k) {
			new_x = present.x + dx[k];
			new_y = present.y + dy[k];
			if (new_x < 0 || new_x >= 4 || new_y < 0 || new_y >= 4) continue;
			st.push({ new_x, new_y, present.num + m[new_x][new_y] });
		}
	}
	
}
int main(int argc, char** argv){
	bb;
	int t;
	cin >> t;
	for(int test_case = 1; test_case <= t; ++test_case){
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> m[i][j];

		set<string> numset;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				solution(i, j, numset);
			}
		}

		cout << '#' << test_case << ' ' << numset.size() << '\n';
	}
	return 0;
}
