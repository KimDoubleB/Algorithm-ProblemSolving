import sys
from collections import deque
input = sys.stdin.readline

user_number, friend_number = map(int, input().split())
friend_relation = [list(map(int, input().split())) for _ in range(friend_number)]
all_relation = [[] for _ in range(user_number)]
kevin_bacon_number = []

for x, y in friend_relation:
    all_relation[x - 1].append(y - 1)
    all_relation[y - 1].append(x - 1)

for ind in range(user_number):
    visited = [False for _ in range(user_number)]
    visited[ind] = True
    
    # bfs
    q = deque([(ind, 0)])
    total_distance = 0
    while q:
        current, distance = q.popleft()
        total_distance += distance
        for next in all_relation[current]:
            if not visited[next]:
                visited[next] = True
                q.append((next, distance + 1))
    kevin_bacon_number.append(total_distance)

minimum_kevin_bacon = min(kevin_bacon_number)
result = kevin_bacon_number.index(minimum_kevin_bacon)
print(result + 1)