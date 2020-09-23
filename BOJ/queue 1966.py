import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, cur = map(int, input().split())
    doc = deque(map(int, input().split()))
    cnt = 1

    while doc:
        if doc[0] == max(doc):
            if cur == 0:
                break
            doc.popleft()
            cnt+=1
            cur-=1
        else:
            doc.append(doc.popleft())
            cur = cur - 1 if cur != 0 else len(doc) - 1

    print(cnt)
