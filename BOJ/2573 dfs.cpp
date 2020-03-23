#include <iostream>
#include <cstring>
#include <stack>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int n, m, map[301][301], melt[301][301];
bool visited[301][301];
stack <pair <int, int> > st;
pair<int, int> present;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
void dfs(int i, int j){
    int new_x, new_y;
    st.push({i, j});
    visited[i][j] = true;
    while(!st.empty()){
        present = st.top();
        st.pop();
        for(int k = 0; k < 4; ++k){
            new_x = present.first + dx[k];
            new_y = present.second + dy[k];
            if(map[new_x][new_y] == 0){
                ++melt[present.first][present.second];
            }
            else if(!visited[new_x][new_y]) {
                st.push({new_x, new_y});
                visited[new_x][new_y] = true;
            }
        }
    }
}
void melting(){
    for(int i = 1; i < n-1; ++i){
        for(int j = 1; j < m-1; ++j){
            map[i][j] -= melt[i][j];
            if(map[i][j] < 0) map[i][j] = 0;
        }
    }
}

int main()
{
	bb;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> map[i][j];
    
    int island, year;
    for(year = 0;; ++year){
        island = 0;
        for(int i = 1; i < n-1; ++i){
            memset(visited[i], 0, sizeof(visited[i]));
            memset(melt[i], 0, sizeof(melt[i]));        
        }
        for(int i = 1; i < n-1; ++i){
            for(int j = 1; j < m-1; ++j){
                if(map[i][j] == 0 || visited[i][j])
                    continue;
                dfs(i, j);
                ++island;
            }
        }
        if(island > 1) break; // 밖에서 year로 출력
        if(island == 0) {
            year = 0;
            break;
        }
        melting();
    }
    cout << year << '\n';
	return 0;
}