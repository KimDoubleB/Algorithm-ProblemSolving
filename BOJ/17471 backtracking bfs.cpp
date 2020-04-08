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
int res = 10'000;
district d[SIZE];
bool check[SIZE], visit[SIZE];
vector<int> v1, v2;
bool connected() {
	int present;

	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(v1[0]);
	visit[v1[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];
			if (visit[n]) continue;
			if (!check[n]) continue;
			q.push(n);
			visit[n] = true;
		}
	}
	for (int i = 0; i < v1.size(); ++i) {
		if (!visit[v1[i]]) return false;
	}


	memset(visit, 0, sizeof(visit));
	q.push(v2[0]);
	visit[v2[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];
			if (visit[n]) continue;
			if (check[n]) continue;
			q.push(n);
			visit[n] = true;
		}
	}
	for (int i = 0; i < v2.size(); ++i) {
		if (!visit[v2[i]]) return false;
	}

	return true;
}


void solution(int cnt, int last) {
	if (cnt == n) return;

	for (int i = last; i < n; ++i) {
		if (check[i]) continue;
		v1.push_back(i);
		check[i] = true;
		solution(cnt + 1, i+1);
		v1.pop_back();
		check[i] = false;
	}
	
	if (cnt == 0) return;

	int aPer = 0;
	v2.clear();
	for (int i = 0; i < n; ++i) {
		if (!check[i])
			v2.push_back(i);
		else
			aPer += d[i].numPer;
	}

	if (connected())
		res = min(abs(aPer - (allPer - aPer)), res);

}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numPer;
		allPer += d[i].numPer;
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numNear;
		for (int j = 0; j < d[i].numNear; ++j) {
			cin >> near[i][j];
			--near[i][j];
		}
	}

	solution(0, 0);

	if (res > 9000)
		cout << -1 << '\n';
	else
		cout << res << '\n';
	return 0;
}