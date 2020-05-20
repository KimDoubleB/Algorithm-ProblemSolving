import sys
input = sys.stdin.readline

n, k = map(int, input().split())
visited = [False] * 100001
ans = 0

# [0]-> val, [1] -> time
q = []
q.append([n, 0])
visited[n] = True
while q:
    now = q.pop(0)
    if now[0] == k:
        ans = now[1]
        break
    if now[0]-1 >= 0 and not visited[now[0]-1]:
        q.append([now[0]-1, now[1]+1])
        visited[now[0]-1] = True
    if now[0]+1 <= 100000 and not visited[now[0]+1]:
        q.append([now[0]+1, now[1]+1])
        visited[now[0]+1] = True
    if now[0]*2 <= 100000 and not visited[now[0]*2]:
        q.append([now[0]*2, now[1]+1])
        visited[now[0]*2] = True

print(ans)