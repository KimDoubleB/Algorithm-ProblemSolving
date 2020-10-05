import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
num, cnt, josephus = deque(range(n)), 1, []

while num:
    num.rotate(-k+1)
    josephus.append(num.popleft()+1)

ans = '<'
for v in josephus:
    ans += str(v)
    if v != josephus[-1]:
        ans += ', '
ans += '>'

print(ans)