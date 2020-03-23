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
	
	// ��� �İ��� ���� ������ ���� ��� ���� �Ǿ��ִ�.
	// �̷��� ���, BFS�� ���鼭 �ּҽð��� ���ؾ� �Ѵ�.
	
	// BFS�� ���, Queue - front() - pop()�� ����ϸ� �ȴ�.
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
