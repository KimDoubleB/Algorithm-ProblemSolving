#include <bits/stdc++.h>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
string maze[102];
int ex[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int main()
{
    bb;
    int row, col, i, j, result = 1;
    cin >> row >> col;
    for (i = 0; i < row; ++i){
        cin >> maze[i];
    }
    queue< pair<int, int> > q;
    q.push({0, 0});
    ex[0][0] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(i = 0; i < 4; ++i){
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];
            if(new_x < 0 | new_y < 0 | new_x >= row | new_y >= col) continue;
            if(maze[new_x][new_y] != '1' | ex[new_x][new_y] > 0) continue;
            ex[new_x][new_y] = ex[cur.first][cur.second] + 1;
            q.push({new_x, new_y});
        }
    }
    cout << ex[row-1][col-1];
}