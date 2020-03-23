#include <iostream>
#include <algorithm>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int num[SIZE];
int n, m;
int binarySearch(int& target){
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = (start+end) / 2;

        if(num[mid] > target){
            end = mid - 1;
        }else if (num[mid] < target){
            start = mid + 1;
        }else{
            return 1;
        }
    }
    return 0;
}
int main()
{
	bb;
    int i, tmp;
    cin >> n;
    for(i = 0; i < n; ++i)
        cin >> num[i];
    sort(num, num+n);
    cin >> m;
    for(i = 0; i < m; ++i){
        cin >> tmp;
        cout << binarySearch(tmp) << '\n';
    }
	return 0;
}