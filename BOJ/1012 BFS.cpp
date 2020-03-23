#include <bits/stdc++.h>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    bb;
    int t;
    cin >> t;
    while(t > 0){
        bool farm[52][52] = {0, };
        bool ex[52][52] = {0, };

        int row, col, pt, numberOfBug = 0;
        cin >> row >> col >> pt;
        while(pt > 0){
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
            --pt;
        }
        queue< pair<int, int> > q;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(ex[i][j] != 0 | farm[i][j] != 1) continue;
                q.push({i, j});
                ex[i][j] = 1;
                ++numberOfBug;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int k = 0; k < 4; ++k){
                        int new_x = cur.first + dx[k];
                        int new_y = cur.second + dy[k];
                        if (new_x < 0 | new_y < 0 | new_x >= row | new_y >= col) continue;
                        if (ex[new_x][new_y] != 0 | farm[new_x][new_y] != 1) continue;
                        ex[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        cout << numberOfBug << "\n";
        --t;
    }
}