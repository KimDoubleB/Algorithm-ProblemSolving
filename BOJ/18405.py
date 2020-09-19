import sys
input = sys.stdin.readline

dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
n, k = map(int, input().split())
m, virus = [], [[] for _ in range(k)]
for i in range(n):
    m.append(list(map(int, input().split())))
    for j in range(n):
        if m[i][j]:
            virus[m[i][j]-1].append((i, j))
s, x, y = map(int, input().split())
x, y = x-1, y-1

while s:
    if m[x][y]:
        break
    for i in range(k):
        cur = []
        for v in virus[i]:
            for j in range(4):
                nx, ny = v[0]+dx[j], v[1]+dy[j]
                if 0 <= nx < n and 0 <= ny < n:
                    if not m[nx][ny]:
                        m[nx][ny] = i+1
                        cur.append((nx, ny))
        virus[i].extend(cur)
    s-=1

print(m[x][y])
