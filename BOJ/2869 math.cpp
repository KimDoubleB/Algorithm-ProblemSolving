#include <iostream>
#include <cmath>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int a, b;
double v;

int main() {
	cin >> a >> b >> v;
	// v로 바로 가면 안됨
	// 10 1 100 인 경우를 생각하면 된다.
	cout << (int)ceil((v - a) / (a - b)) + 1 << '\n';
	return 0;
}