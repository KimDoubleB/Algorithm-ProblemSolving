#include <iostream>
#define bb ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()	
{
	bb;
	int n, x, i, tmp;
	cin >> n >> x;
	for (i = 0; i < n; ++i) {
		cin >> tmp;
		if (tmp < x)
			cout << tmp << ' ';
	}
	return 0;
}
