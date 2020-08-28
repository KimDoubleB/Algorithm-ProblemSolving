n, m = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(n)]
v, visit = [], [[False] * m for _ in range(n)]
safe, vnum = 0, 70

for i in range(n):
    for j in range(m):
        if(lab[i][j] == 2):
            v.append((i, j))
        if (lab[i][j] != 1):
            safe += 1

def dfs(x, y):
    visit[x][y] = True
    res = 1
    for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0):
        nx, ny = x+dx, y+dy
        if nx >= n or nx < 0 or ny >= m or ny < 0:
            continue
        if visit[nx][ny]:
            continue
        if lab[nx][ny] == 0:
            res += dfs(nx, ny)
    return res

def solve(x, y, c):
    global vnum, visit
    if c == 3:
        visit = [[False] * m for _ in range(n)]
        cnt = 0
        for i, j in v:
            cnt += dfs(i, j)
        vnum = min(vnum, cnt)
    else:
        for i in range(x, n):
            if i != x:
                y = 0
            for j in range(y, m):
                if lab[i][j] == 0:
                    lab[i][j] = 1
                    solve(i, j+1, c+1)
                    lab[i][j] = 0

solve(0, 0, 0)
print(safe - 3 - vnum)
