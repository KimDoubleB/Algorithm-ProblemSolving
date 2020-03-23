#include <iostream>
#include <algorithm>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
typedef long long ll;

ll new_pow(ll a, ll b, ll m){
    if(b == 0) return 1;      // base condition
    // b is ODD: (a^k)^2 * a
    // b is EVEN: (a^k)^2
    ll val = new_pow(a, b/2, m);
    val = val * val % m;      // continuoulsy calculate remainder
    if(b % 2 == 0) return val;
    return val * a % m;
}
int main()
{
	bb;
	ll a,b,c;
    cin >> a >> b >> c;
    cout << new_pow(a,b,c);
    return 0;
}