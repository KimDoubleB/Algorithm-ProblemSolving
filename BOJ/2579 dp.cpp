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
		x ��ġ������ �ȱ� �ִ� ��
		
		stmax[x][0]: 2�� �ȱ� �� ��ġ
		--> 2��° �Ʒ� ��ܿ��� ����
		--> 1���� 2�� �ȱ��� ��ġ �� �� ����
		
		stmax[x][1]: 1�� �ȱ� �� ��ġ 
		--> 1��° �Ʒ� ��ܿ��� ����
		--> 2�� �ȱ��� ��ġ������ �̵����� 
	*/

	stmax[1][0] = st[1];
	for (int i = 2; i < n+1; ++i) {

		stmax[i][0] = max(stmax[i - 2][0], stmax[i - 2][1]) + st[i];
		stmax[i][1] = stmax[i - 1][0] + st[i];
	}
	cout << max(stmax[n][1], stmax[n][0]) << '\n';
	
	return 0;
}
