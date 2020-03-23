#include <iostream>
#define SIZE 11
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int arr[SIZE], n, k;
int main()
{
	bb;
    int num, res = 0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = n-1; i >= 0; --i){
        if(k==0) break;
        num = k / arr[i];
        if(num > 0){
            res += num;
            k -= (num*arr[i]);
        }
    }

    cout << res << '\n';
	return 0;
}