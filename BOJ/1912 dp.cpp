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

		// ���� �������� ���ϴ°� ������? �ƴϸ� ���簪�� �������� �����ΰ� ������?
		nummax[i] = max(nummax[i - 1] + num[i], num[i]);
		
		// �ܰ踶�� �������� �ְ��� �����ش�.
		if (result < nummax[i]) result = nummax[i];
	}
	cout << result << '\n';
	return 0;
}
