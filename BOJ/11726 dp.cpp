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
	// ��ȭ�� ����
	/*
		�����غ��� �ſ� ����.
		n��° Ÿ���� 
		=> n-1 Ÿ�Ͽ� '���� Ÿ��' �ϳ� ���̴� ���
		=> n-2 Ÿ�Ͽ� '���� Ÿ��'x2 �Ǵ� '���� Ÿ��'x2 ���̴� ���

		--> �ᱹ�� �� 2���� ��� �ۿ� �����Ƿ�, n-1��� + n-2��찡 n ��츦 ��Ÿ���� �ȴ�.
	*/
	for (int i = 3; i <= n; ++i)
		tile[i] = (tile[i - 1] % remainder) + (tile[i - 2] % remainder);
	cout << tile[n] % remainder << '\n';
	
	return 0;
}
