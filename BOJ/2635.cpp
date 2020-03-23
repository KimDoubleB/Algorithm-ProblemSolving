#include <iostream>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL)
using namespace std;
int n, fn1, fn2, tmp;
void func(vector<int>& arr) {
	tmp = fn1 - fn2;
	if (tmp < 0) return;
	arr.push_back(tmp);
	fn1 = fn2;
	fn2 = tmp;
	return func(arr);
}
int main()
{
	bb;
	cin >> n;
	vector<int> res;
	int max = 2;
	for (int i = n; i >= 1; --i) {
		vector<int> arr;
		fn1 = n, fn2 = i;
		arr.push_back(fn1);
		arr.push_back(fn2);
		func(arr);
		if (arr.size() > max) {
			max = arr.size();
			res = arr;
		}
	}
	cout << max << '\n';
	for (int i = 0; i < max; ++i)
		cout << res[i] << ' ';
	return 0;
}