# Dirty code.....
# Update soon.....

from collections import deque
from copy import deepcopy

n = int(input())
ma = [[0 for _ in range(n)] for _ in range(n)]
start, target = map(int, input().split())
start, target = start-1, target-1

m = int(input())
for _ in range(m):
    t1, t2 = map(int, input().split())
    ma[t1-1][t2-1] = ma[t2-1][t1-1] = 1

cnt = -1
visited = []
queue = [[start, visited, 1]]
while len(queue):
    present = queue.pop(0)
    if ma[present[0]][target] == 1:
        cnt = present[2]
        break
    for i in range(n):
        if ma[present[0]][i] == 0 or i in present[1]:
            continue
        present[1].append(present[0])
        queue.append([i, deepcopy(present[1]), present[2]+1])
        present[1].pop()

print(cnt)
