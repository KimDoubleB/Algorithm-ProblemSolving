#include <bits/stdc++.h>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int dx[4] = {0, 1, 3, 4};
int main()
{
    bb;
    for(int t=1; t<=10; ++t){
        int len, result=0;
        vector<int> vec;
        cin >> len;
        while(len>0){
            int h;
            cin >> h;
            vec.push_back(h);
            if(vec.size() == 5){
                int min = 256;
                for(int i = 0; i < 4; ++i){
                    int diff = vec[2] - vec[dx[i]];
                    if(diff <= 0){
                        min=0;
                        break;
                    }
                    if(diff < min) min = diff;
                }
                result += min;
                vec.erase(vec.begin());
            }
            --len;
        }
        cout << '#' << t << ' ' << result << '\n';
    }
}