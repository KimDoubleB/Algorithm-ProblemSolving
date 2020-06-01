import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
net = [[] for _ in range(n)]
dest = [0 for _ in range(n)]
for _ in range(m):
    t = list(map(int, input().split()))
    for i in range(len(t)):
        if i <= 1: continue
        net[t[i-1]-1].append(t[i]-1)
        dest[t[i]-1] += 1


def dfs(here):
    dest[here] = -999
    order.append(here)
    for nxt in net[here]:
        dest[nxt] -= 1
        if not dest[nxt]:
            dfs(nxt)

order = []
for i, v in enumerate(dest):
    if not v: 
        dfs(i)
        
if len(order) < n: print(0)
else:
    for o in order:
        print(o+1)