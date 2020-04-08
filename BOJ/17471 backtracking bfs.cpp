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
int res = 10'000;	// 인구차이는 100*10을 넘을 수 없다.
district d[SIZE];
bool check[SIZE], visit[SIZE];
vector<int> v1, v2; // 2개의 선거구


// 선거구가 연결되어 있는가? True/False
bool connected() {
	int present;

	// BFS를 활용하자
	memset(visit, 0, sizeof(visit)); // visit 초기화
	queue<int> q; 
	
	// 첫 번째 선거구 - BFS 레퍼토리 시작
	q.push(v1[0]);
	visit[v1[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];	// 인접해 있는 지역 넣기
			if (visit[n]) continue;		// 이미 들렸던 곳인 경우, 패스
			if (!check[n]) continue;	// 다른 선거구일 경우, 패스
			q.push(n);
			visit[n] = true;
		}
	}

	// 첫 번째 선거구 지역을 다 돌았는가? --> 다 연결되어 있는가 확인
	for (int i = 0; i < v1.size(); ++i) {
		if (!visit[v1[i]]) return false;
	}


	memset(visit, 0, sizeof(visit)); // visit 초기화

	// 두 번쨰 선거구 - BFS 레퍼토리 시작
	q.push(v2[0]);
	visit[v2[0]] = true;
	while (!q.empty()) {
		present = q.front();
		q.pop();
		for (int j = 0; j < d[present].numNear; ++j) {
			int n = near[present][j];	// 인접해 있는 지역 넣기
			if (visit[n]) continue;		// 이미 들렸던 곳인 경우, 패스
			if (check[n]) continue;		// 다른 선거구일 경우, 패스
			q.push(n);
			visit[n] = true;
		}
	}

	// 두 번째 선거구 지역을 다 돌았는가? --> 다 연결되어 있는가 확인
	for (int i = 0; i < v2.size(); ++i) {
		if (!visit[v2[i]]) return false;
	}

	return true;
}

// 백트랙킹 --> 전체경우 확인
// 선거구 확인하고, 가능하면 인구차이 최소 값 계산 및 비교
void solution(int cnt, int last) {
	// n인 경우, 한 선거구로 다 몰린 경우이므로 패스
	if (cnt == n) return; 

	/*
	백트랙킹.
	- 1, 5 선택하는 것과 5, 1 선택하는 것은 같은 경우 이므로 0부터 할 필요없다.
	- 전 선택의 마지막 값을 받아서 그 값 이상인 경우만 순회하면 된다.
	
	- 선택하는 과정은 한 번만 하면 된다. 선택하지 않은 선거구를 또 다른 선거구로 지정하면 되므로.
	- 선택한 선거구 v1, 선택하지 않은 선거구 v2
	*/
	for (int i = last; i < n; ++i) {
		if (check[i]) continue;
		v1.push_back(i);
		check[i] = true;
		solution(cnt + 1, i+1);
		v1.pop_back();
		check[i] = false;
	}
	
	// 0인 경우도 한 선거구로 다 몰린 경우이므로 패스
	if (cnt == 0) return;

	int aPer = 0;	// 선택한 선거구의 인구 수
	v2.clear();
	for (int i = 0; i < n; ++i) {
		if (!check[i])
			v2.push_back(i);	// 선택하지 않은 선거구 -> v2
		else
			aPer += d[i].numPer;
	}

	// v1, v2 다 각 선거구 연결되어있는 경우,
	if (connected())
		res = min(abs(aPer - (allPer - aPer)), res); // 인구차이 최소값 계산 및 비교

}


int main() {
	// input
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numPer;
		allPer += d[i].numPer;	// 전체 인구수 계산
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i].numNear;
		for (int j = 0; j < d[i].numNear; ++j) {
			cin >> near[i][j];
			--near[i][j]; // 배열 인덱스 접근하는 것이므로 1을 빼줌
		}
	}

	solution(0, 0);	

	if (res > 9000)
		cout << -1 << '\n';
	else
		cout << res << '\n';
	return 0;
}