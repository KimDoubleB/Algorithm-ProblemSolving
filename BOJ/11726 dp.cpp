#include <iostream>
#define SIZE 1001
#define remainder 10'007
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int tile[SIZE];
int main()	
{
	bb;
	int n;
	cin >> n;
	tile[1] = 1;
	tile[2] = 2;
	// 점화식 구현
	/*
		생각해보면 매우 쉽다.
		n번째 타일은 
		=> n-1 타일에 '세로 타일' 하나 붙이는 경우
		=> n-2 타일에 '세로 타일'x2 또는 '가로 타일'x2 붙이는 경우

		--> 결국엔 이 2가지 경우 밖에 없으므로, n-1경우 + n-2경우가 n 경우를 나타내게 된다.
	*/
	for (int i = 3; i <= n; ++i)
		tile[i] = (tile[i - 1] % remainder) + (tile[i - 2] % remainder);
	cout << tile[n] % remainder << '\n';
	
	return 0;
}
