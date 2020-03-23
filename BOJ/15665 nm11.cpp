#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 8
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int n, m, arr[SIZE], isUsed[SIZE];
void nm(vector<int>& vec, int k){
    if(k==m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        int before = -1; // 이전 값과 같은 것을 mask 하기 위함 (지역변수)
        for(int i = 0; i < n; ++i){
            if(before == vec[i]) continue; // 이전 값과 같은 것이면 pass
            arr[k] = vec[i];
            before = vec[i];
            nm(vec, k+1);
        }
    }
}
int main()
{
	bb;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    nm(vec, 0);
	return 0;
}