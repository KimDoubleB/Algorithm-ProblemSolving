#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ori[7], ans[7], visited[7];
int main(int argc, char** argv){
	bb;
	int t, n, cnt;
	string str;
	cin >> t;
	for(int test_case = 1; test_case <= t; ++test_case){
		// init
		memset(ori, 0, sizeof(ori));
		memset(ans, 0, sizeof(ans));
		memset(visited, 0, sizeof(visited));

		// input
		cin >> str >> cnt;
		n = str.size();
		for (int i = 0; i < n; ++i)
			ori[i] = ans[i] = str[i] - '0';

		// size 1 case
		if (n == 1) {
			cout << '#' << test_case << ' ' << ori[0] << '\n';
		}

		// get answer (ideal)
		sort(ans, ans + n, greater<int>());

		// swap solution
		int target = 0;
		bool isSwap, sameNum = false;
		for (int i = 0; i < n-1; ++i) {
			// 같은 값 있나 확인 -> 무조건 바꿔야해도 같은 값을 바꾸면 안바꾸는 효과를 볼 수 있음.
			if (ans[i] == ans[i + 1]) sameNum = true; 
			
			// 바꿈 횟수 확인
			if (cnt == 0) break;

			// 바꿨던 곳인가 확인 -> 시간 단축
			if (visited[i]) continue;

			// 현재 인덱스에서 정답값과 동일하면 바꾸지 않음
			if (ori[i] == ans[i]) continue;

			isSwap = false;
			for (int j = i+1; j < n; ++j) {
				if (ori[j] == ans[i]) {
					target = j;

					// 바꿔지는 곳의 정답값도 현재 인덱스 값과 같으면 그냥 바꾸는 것으로 끝
					if (ori[i] == ans[j]) {
						swap(ori[i], ori[j]);
						cnt--;
						visited[j] = true;
						isSwap = true;
						break;
					}
				}
			}

			// 한 번 바뀌어서 최종값으로 바꿀 수 없는 경우, 일단 강제적으로 최종값에 해당하는 값으로 채워 넣는다.
			// --> 이렇게 되면 현재 위치의 최종값은 되지만, 바꿔진 곳의 최종값은 아니게 된다.
			if (!isSwap) {
				swap(ori[i], ori[target]);
				cnt--;
			}
		}
		
		// cnt가 남으면,
		if (cnt) {
			if (cnt % 2 && !sameNum) {
				swap(ori[n - 2], ori[n - 1]);
			}
		}

		// print
		cout << '#' << test_case << ' ';
		for (int i = 0; i < n; ++i)
			cout << ori[i];
		cout << '\n';

	}
	return 0;
}
