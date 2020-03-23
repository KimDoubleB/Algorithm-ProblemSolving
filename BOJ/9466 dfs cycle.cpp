#include <iostream>
#include <cstring>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int node[SIZE], visited_node[SIZE], first_node[SIZE];
int start;
int dfs(int now, int cnt) { // return 값이 사이클 형성된 노드 개수
	if (visited_node[now]) {
		// 들렸을 경우,
		// 1. 이번 순회에서 들린 곳을 다시 들린 경우
		// --> 시작노드가 무엇이었냐로 통해 인식 가능
		// --> count를 계산
		if (first_node[now] == start)
			return cnt - visited_node[now];

		// 2. 이전 순회에서 들린 곳을 다시 들린 경우
		// --> 사이클 없음, 종료
		return 0;
	}
	else {
		// 안들린 경우, 들렸다고 표시 및 첫번째 시작한 노드도 등록
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
		cout << T - result << '\n'; // 사이클 못 이룬 개수 출력
	}
	return 0;
}