#include <iostream>
#include <algorithm>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int r[SIZE];
int main()
{
	bb;
    int n, tmp, res=-1;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> r[i];
    sort(r, r+n);
    for(int i = 0; i < n; ++i){
        tmp = r[i] * (n-i);
        res = max(tmp, res);
    }
    cout << res << '\n';
	return 0;
}