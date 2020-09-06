from collections import deque

n, m = map(int, input().split())
target = deque(map(int, input().split()))
q = deque([x for x in range(1, n+1)])
cnt = 0
while len(target):
    t = target.popleft()
    t_point = q.index(t)
    if t_point != 0:
        if len(q)-t_point > t_point:
            q.rotate(-t_point)
            cnt += t_point
        else:
            q.rotate(len(q)-t_point)
            cnt += len(q)-t_point
    q.popleft()
print(cnt)
