from collections import deque

dx, dy = [-1, -1, -2, -2, 1, 1, 2, 2], [-2, 2, -1, 1, -2, 2, -1, 1]

t = int(input())
for _ in range(t):
    n = int(input())
    m = [[0]*n for _ in range(n)]
    cur = tuple(map(int, input().split()))
    target = tuple(map(int, input().split()))
    pnt = deque([cur])
    while len(pnt) > 0:
        cur = pnt.popleft()
        if target[0] == cur[0] and target[1] == cur[1]:
            # Arrive
            print(m[cur[0]][cur[1]])
            break
        
        for i in range(8):
            nx, ny = dx[i]+cur[0], dy[i]+cur[1]
            if nx < 0 or nx >= n or ny < 0 or ny >= n or m[nx][ny] > 0:
                continue
            m[nx][ny] = m[cur[0]][cur[1]]+1
            pnt.append((nx,ny))



