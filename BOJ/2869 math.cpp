#include <iostream>
#include <cmath>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int a, b;
double v;

int main() {
	cin >> a >> b >> v;
	// v�� �ٷ� ���� �ȵ�
	// 10 1 100 �� ��츦 �����ϸ� �ȴ�.
	cout << (int)ceil((v - a) / (a - b)) + 1 << '\n';
	return 0;
}