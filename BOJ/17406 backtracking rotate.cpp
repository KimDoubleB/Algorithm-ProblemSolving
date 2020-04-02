#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 51
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int N, M, K, res = 10'000;
int oriA[SIZE][SIZE], A[SIZE][SIZE], B[7][3];
bool check[7];
vector<int> vec;

void rotate(int r, int c, int s) {
	for (int i = 1; i <= s; ++i) {
		int last = A[r - i + 1][c - i];
		int new_r = r - i + 1;
		int new_c = c - i;

		// 시계방향 회전
		while (r + i > new_r) {
			A[new_r][new_c] = A[new_r + 1][new_c];
			new_r++;
		}
		while (c + i > new_c) {
			A[new_r][new_c] = A[new_r][new_c + 1];
			new_c++;
		}
		while (new_r > r - i) {
			A[new_r][new_c] = A[new_r - 1][new_c];
			new_r--;
		}
		while (new_c > c - i) {
			A[new_r][new_c] = A[new_r][new_c - 1];
			new_c--;
		}
		A[new_r][new_c] = last;
	}
}

void solution(int cnt) {
	if (cnt == K) { // 회전 방법 다 고른 경우
		
		copy(&oriA[0][0], &oriA[0][0] + SIZE * SIZE, &A[0][0]); // 회전 시뮬레이션을 위해 복사

		// 고른 회전 방법 다 수행
		for (int i = 0; i < K; ++i) {
			rotate(B[vec[i]][0] - 1, B[vec[i]][1] - 1, B[vec[i]][2]); // 회전 보낼 때, 행과 열에 -1 주고 보내야 함.
		}

		// 배열의 값 (행의 합의 최소값 계산 및 비교)
		for (int i = 0; i < N; ++i) {
			int rsum = 0;
			for (int j = 0; j < M; ++j) {
				rsum += A[i][j];
			}
			res = min(res, rsum);
		}

		return;
	}

	// selecting
	for (int i = 0; i < K; ++i) {
		if (check[i]) continue;
		vec.push_back(i);
		check[i] = true;
		solution(cnt + 1);
		vec.pop_back();
		check[i] = false;
	}
}

int main()
{
	// input
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> oriA[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		cin >> B[i][0] >> B[i][1] >> B[i][2];
	}

	// play
	solution(0);

	cout << res << '\n';
	return 0;
}