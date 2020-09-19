import sys
from collections import deque
input = sys.stdin.readline
n, m, k, x = map(int, input().split())
road, visited, cnt = [[] for _ in range(n)], [0] * n, []
for _ in range(m):
    i, j = map(int, input().split())
    road[i-1].append(j-1)

q = deque([(x-1, 0)])
visited[x-1] = 1
while q:
    cur, cost = q.popleft()
    if cost == k:
        cnt.append(cur+1)
        continue
    for dst in road[cur]:
        if not visited[dst]:
            q.append((dst, cost+1))
            visited[dst] = 1

cnt.sort()
if len(cnt):
    for c in cnt:
        print(c)
else:
    print(-1)

