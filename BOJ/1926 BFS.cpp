#include <bits/stdc++.h>
#define bb                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
bool pic[502][502];
bool ex[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    bb;
    int row, col, i, j;
    cin >> row >> col;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
            cin >> pic[i][j];
    queue<pair<int, int>> q;
    int numberOfPicture = 0, maxSize = 0;
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            if (ex[i][j] == 1 | pic[i][j] == 0) continue;
            ++numberOfPicture;
            q.push({i, j});
            ex[i][j] = 1;
            int sizeOfPicture = 0;
            while (!q.empty())
            {
                int p_row = q.front().first;
                int p_col = q.front().second;
                q.pop();
                ++sizeOfPicture;

                for(int k = 0; k < 4; ++k){
                    int new_row = p_row + dx[k];
                    int new_col = p_col + dy[k];
                    if(new_row < 0 | new_row >= row | new_col < 0 | new_col >= col) continue;
                    if(ex[new_row][new_col] == 1 | pic[new_row][new_col] == 0) continue;
                    q.push({new_row, new_col});
                    ex[new_row][new_col] = 1;
                }
            }
            maxSize = max(maxSize, sizeOfPicture);
        }
    }
    cout << numberOfPicture << "\n" << maxSize;
}