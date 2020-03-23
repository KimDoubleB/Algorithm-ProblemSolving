#include <iostream>
#include <vector>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int n, res, col[11];
bool isOk(int q){
    for(int j = 0; j < q; ++j){ // row 순회라고 보면 된다.
        if(col[q]==col[j] || (q-j == abs(col[q]-col[j]))) // row와 그 해당 row에서 col간에 차의 절대값이 같으면 대각선에 해당
            return false;
    }
    return true;
}
void queen(int q){
    if(n==q) ++res;
    else{
        for(int i = 0; i < n; ++i){ 
            col[q] = i; // col 번호에 넣어보고, 이게 되면 넘어가게 끔 만듦.
            if(isOk(q)) queen(q+1);
        }
    }
}
int main()
{
    bb;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        cin >> n;
        res = 0;
        queen(0);
        cout << '#' << tt << ' ' << res << '\n';
    }
    return 0;
}