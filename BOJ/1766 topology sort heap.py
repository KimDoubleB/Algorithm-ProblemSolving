import heapq
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
net = [[] for _ in range(n)]
idg = [0 for _ in range(n)]
for _ in range(m):
    t1, t2 = map(int, input().split())
    net[t1-1].append(t2-1)
    idg[t2-1]+=1


ans = []

for i, v in enumerate(idg):
    if not v:
        st = []
        heapq.heappush(st, i)
        while st:
            here = heapq.heappop(st)
            idg[here] = -999
            ans.append(here)
            for nxt in net[here]:
                idg[nxt] -= 1
                if not idg[nxt]:
                    heapq.heappush(st, nxt)

for v in ans:
    print(v+1, end=" ")




