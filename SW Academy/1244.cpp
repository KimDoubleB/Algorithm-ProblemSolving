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
			// ���� �� �ֳ� Ȯ�� -> ������ �ٲ���ص� ���� ���� �ٲٸ� �ȹٲٴ� ȿ���� �� �� ����.
			if (ans[i] == ans[i + 1]) sameNum = true; 
			
			// �ٲ� Ƚ�� Ȯ��
			if (cnt == 0) break;

			// �ٲ�� ���ΰ� Ȯ�� -> �ð� ����
			if (visited[i]) continue;

			// ���� �ε������� ���䰪�� �����ϸ� �ٲ��� ����
			if (ori[i] == ans[i]) continue;

			isSwap = false;
			for (int j = i+1; j < n; ++j) {
				if (ori[j] == ans[i]) {
					target = j;

					// �ٲ����� ���� ���䰪�� ���� �ε��� ���� ������ �׳� �ٲٴ� ������ ��
					if (ori[i] == ans[j]) {
						swap(ori[i], ori[j]);
						cnt--;
						visited[j] = true;
						isSwap = true;
						break;
					}
				}
			}

			// �� �� �ٲ� ���������� �ٲ� �� ���� ���, �ϴ� ���������� �������� �ش��ϴ� ������ ä�� �ִ´�.
			// --> �̷��� �Ǹ� ���� ��ġ�� �������� ������, �ٲ��� ���� �������� �ƴϰ� �ȴ�.
			if (!isSwap) {
				swap(ori[i], ori[target]);
				cnt--;
			}
		}
		
		// cnt�� ������,
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
