#include <bits/stdc++.h>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int main()
{
    bb;
    int t;
    cin >> t;
    for(int x=0; x<t; ++x){
        int k;
        unsigned long sum = 0;
        cin >> k;
        stack<int> st;
        while(k > 0){
            int val;
            cin >> val;
            if(val != 0){
                st.push(val);
                sum += val;
            }
            else{
                sum -= st.top();
                st.pop();
            }
            --k;
        }
        cout << '#' << x+1 << ' ' << sum << '\n';
    }
}