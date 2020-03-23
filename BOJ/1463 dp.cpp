#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int f[1'000'002];
int main()
{
	bb;
    int n;
    cin >> n;
    f[1] = 0;
    for(int i = 2; i <= n; ++i){
        f[i] = f[i-1] + 1;
        if(i%2 == 0) f[i] = min(f[i], f[i/2]+1);
        if(i%3 == 0) f[i] = min(f[i], f[i/3]+1);
    }
    cout << f[n] << '\n';
	return 0;
}
