import collections

n = int(input())
m = int(input())
net = [ [] for _ in range(n)]
for _ in range(m):
    t1, t2 = map(int, input().split())
    net[t1-1].append(t2-1)
    net[t2-1].append(t1-1)


def bfs(start):
    q = collections.deque()
    visited = [False] * n
    q.append(start)
    visited[start] = True
    cnt = 0
    
    while q:
        for _ in range(len(q)):
            cnt += 1
            present = q.popleft();
            for adj in net[present]:
                if not visited[adj]: 
                    q.append(adj)
                    visited[adj] = True
    
    return cnt-1
        
print(bfs(0))