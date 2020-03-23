#include <iostream>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int st[301], stmax[301][2];

int main()
{
	bb;
	int n;
	cin >> n;
	for (int i = 1; i < n+1; ++i)
		cin >> st[i];

	/*
		x 위치에서의 걷기 최대 값
		
		stmax[x][0]: 2번 걷기 할 위치
		--> 2번째 아래 계단에서 시작
		--> 1번과 2번 걷기한 위치 둘 다 가능
		
		stmax[x][1]: 1번 걷기 할 위치 
		--> 1번째 아래 계단에서 시작
		--> 2번 걷기한 위치에서만 이동가능 
	*/

	stmax[1][0] = st[1];
	for (int i = 2; i < n+1; ++i) {

		stmax[i][0] = max(stmax[i - 2][0], stmax[i - 2][1]) + st[i];
		stmax[i][1] = stmax[i - 1][0] + st[i];
	}
	cout << max(stmax[n][1], stmax[n][0]) << '\n';
	
	return 0;
}
