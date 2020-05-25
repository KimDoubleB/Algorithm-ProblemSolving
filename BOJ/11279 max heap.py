import heapq
import sys
input = sys.stdin.readline

n = int(input())

num = []
for _ in range(n):
    val = int(input())
    if val < 1:
        if len(num) < 1:
            print(0)
        else:
            print(heapq.heappop(num)[1])
    else:
        heapq.heappush(num, (-val, val))