#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 11
using namespace std;
struct district {
	int numPer, numNear;
};
int n, near[SIZE][SIZE], allPer;
int res = 10'000;	// �α����̴� 100*10�� ���� �� ����.
district d[SIZE];
bool check[SIZE], visit[SIZE];
vector<int> v1, v2; // 2���� ���ű�


// ���ű��� ����Ǿ� �ִ°�? True/False
bool connected() {
	int present;

	// BFS�� Ȱ������
	memset(visit, 0, sizeof(visit)); // visit �ʱ�ȭ
	queue<int> q; 
	
	// ù ��° ���ű� - BFS �����丮 ����
	q.push(v1[0]);
	visit[v1[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];	// ������ �ִ� ���� �ֱ�
			if (visit[n]) continue;		// �̹� ��ȴ� ���� ���, �н�
			if (!check[n]) continue;	// �ٸ� ���ű��� ���, �н�
			q.push(n);
			visit[n] = true;
		}
	}

	// ù ��° ���ű� ������ �� ���Ҵ°�? --> �� ����Ǿ� �ִ°� Ȯ��
	for (int i = 0; i < v1.size(); ++i) {
		if (!visit[v1[i]]) return false;
	}


	memset(visit, 0, sizeof(visit)); // visit �ʱ�ȭ

	// �� ���� ���ű� - BFS �����丮 ����
	q.push(v2[0]);
	visit[v2[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];	// ������ �ִ� ���� �ֱ�
			if (visit[n]) continue;		// �̹� ��ȴ� ���� ���, �н�
			if (check[n]) continue;		// �ٸ� ���ű��� ���, �н�
			q.push(n);
			visit[n] = true;
		}
	}

	// �� ��° ���ű� ������ �� ���Ҵ°�? --> �� ����Ǿ� �ִ°� Ȯ��
	for (int i = 0; i < v2.size(); ++i) {
		if (!visit[v2[i]]) return false;
	}

	return true;
}

// ��Ʈ��ŷ --> ��ü��� Ȯ��
// ���ű� Ȯ���ϰ�, �����ϸ� �α����� �ּ� �� ��� �� ��
void solution(int cnt, int last) {
	// n�� ���, �� ���ű��� �� ���� ����̹Ƿ� �н�
	if (cnt == n) return; 

	/*
	��Ʈ��ŷ.
	- 1, 5 �����ϴ� �Ͱ� 5, 1 �����ϴ� ���� ���� ��� �̹Ƿ� 0���� �� �ʿ����.
	- �� ������ ������ ���� �޾Ƽ� �� �� �̻��� ��츸 ��ȸ�ϸ� �ȴ�.
	
	- �����ϴ� ������ �� ���� �ϸ� �ȴ�. �������� ���� ���ű��� �� �ٸ� ���ű��� �����ϸ� �ǹǷ�.
	- ������ ���ű� v1, �������� ���� ���ű� v2
	*/
	for (int i = last; i < n; ++i) {
		if (check[i]) continue;
		v1.push_back(i);
		check[i] = true;
		solution(cnt + 1, i+1);
		v1.pop_back();
		check[i] = false;
	}
	
	// 0�� ��쵵 �� ���ű��� �� ���� ����̹Ƿ� �н�
	if (cnt == 0) return;

	int aPer = 0;	// ������ ���ű��� �α� ��
	v2.clear();
	for (int i = 0; i < n; ++i) {
		if (!check[i])
			v2.push_back(i);	// �������� ���� ���ű� -> v2
		else
			aPer += d[i].numPer;
	}

	// v1, v2 �� �� ���ű� ����Ǿ��ִ� ���,
	if (connected())
		res = min(abs(aPer - (allPer - aPer)), res); // �α����� �ּҰ� ��� �� ��

}


int main() {
	// input
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numPer;
		allPer += d[i].numPer;	// ��ü �α��� ���
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numNear;
		for (int j = 0; j < d[i].numNear; ++j) {
			cin >> near[i][j];
			--near[i][j]; // �迭 �ε��� �����ϴ� ���̹Ƿ� 1�� ����
		}
	}

	solution(0, 0);	

	if (res > 9000)
		cout << -1 << '\n';
	else
		cout << res << '\n';
	return 0;
}