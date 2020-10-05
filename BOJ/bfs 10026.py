import sys
input = sys.stdin.readline

def bfs(color, i, j):
    q = [(i, j)]
    while len(q) != 0:
        pos = q.pop(0)
        x = pos[0]
        y = pos[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if -1 < nx < n and -1 < ny < n and pic[nx][ny] in color and not visited[nx][ny]:
                visited[nx][ny] = True
                q.append((nx, ny))

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
n = int(input())
pic = [list(input()) for _ in range(n)]
cnt, cnt_rgb = 0, 0

visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            bfs(list(pic[i][j]), i, j)
            cnt += 1

visited = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            if pic[i][j] == 'R' or pic[i][j] == 'G':
                bfs(['R', 'G'], i, j)
            else:
                bfs(['B'], i, j)
            cnt_rgb += 1

print(cnt, cnt_rgb)