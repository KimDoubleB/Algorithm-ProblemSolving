#include <iostream>
#include <algorithm>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int num[SIZE], nummax[SIZE];
int main()	
{
	bb;
	int n, result = -1001;
	cin >> n;
	for (int i = 1; i < n+1; ++i) {
		cin >> num[i];

		// 기존 연속합을 더하는게 나은가? 아니면 현재값이 연속합의 시작인게 나은가?
		nummax[i] = max(nummax[i - 1] + num[i], num[i]);
		
		// 단계마다 연속합의 최고값과 비교해준다.
		if (result < nummax[i]) result = nummax[i];
	}
	cout << result << '\n';
	return 0;
}
