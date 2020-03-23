#include <iostream>
#include <cstring>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int node[SIZE], visited_node[SIZE], first_node[SIZE];
int start;
int dfs(int now, int cnt) { // return ���� ����Ŭ ������ ��� ����
	if (visited_node[now]) {
		// ����� ���,
		// 1. �̹� ��ȸ���� �鸰 ���� �ٽ� �鸰 ���
		// --> ���۳�尡 �����̾��ķ� ���� �ν� ����
		// --> count�� ���
		if (first_node[now] == start)
			return cnt - visited_node[now];

		// 2. ���� ��ȸ���� �鸰 ���� �ٽ� �鸰 ���
		// --> ����Ŭ ����, ����
		return 0;
	}
	else {
		// �ȵ鸰 ���, ��ȴٰ� ǥ�� �� ù��° ������ ��嵵 ���
		visited_node[now] = cnt;
		first_node[now] = start;
		return dfs(node[now], cnt + 1);
	}
}


int main()
{
	bb;
	int test_case;
	cin >> test_case;
	for (int tt = 0; tt < test_case; ++tt) {
		// input
		int T, result;
		cin >> T;
		memset(visited_node, 0, sizeof(visited_node));
		memset(first_node, 0, sizeof(first_node));
		for (int i = 0; i < T; ++i) {
			cin >> node[i];
			node[i] -= 1;
		}
		
		// dfs process
		result = 0;
		for (int i = 0; i < T; ++i) {
			if (!visited_node[i]) {
				start = i;	// define start node
				result += dfs(i, 1);
			}
		}
		cout << T - result << '\n'; // ����Ŭ �� �̷� ���� ���
	}
	return 0;
}