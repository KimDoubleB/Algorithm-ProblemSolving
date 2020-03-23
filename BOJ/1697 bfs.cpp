#include <iostream>
#include <queue>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
bool isVistied[100'001];
int n, k, res;

int main()
{
	bb;
	cin >> n >> k;
	
	// 깊게 파고가다 보면 무조건 무한 대로 돌게 되어있다.
	// 이러한 경우, BFS로 돌면서 최소시간을 구해야 한다.
	
	// BFS의 경우, Queue - front() - pop()을 사용하면 된다.
	queue< pair<int, int> > q;
	q.push({ n, 0 });

	
	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		if (now == k) {
			res = time;
			break;
		}
		q.pop();
		isVistied[now] = true;
		if (now - 1 >= 0 && isVistied[now - 1] == false)
			q.push({ now - 1, time + 1 });
		if (now + 1 <= 100'000 && isVistied[now + 1] == false)
			q.push({ now + 1, time + 1 });
		if (now * 2 <= 100'000 && isVistied[now * 2] == false)
			q.push({ now * 2, time + 1 });
	}
	cout << res << '\n';
	return 0;
}
