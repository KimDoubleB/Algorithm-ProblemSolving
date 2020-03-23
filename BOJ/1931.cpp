#include <iostream>
#include <algorithm>
#define SIZE 100'001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int n;
pair<int, int> time[SIZE];
int main()
{
	bb;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> time[i].second >> time[i].first;
    sort(time, time+n);
    int endTime = -1, res = 0;
    for(int i = 0; i < n; ++i){
        if(time[i].second >= endTime){
            endTime = time[i].first;
            ++res;
        }
    }
    cout << res << '\n';
	return 0;
}