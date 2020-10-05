import itertools
import sys
input = sys.stdin.readline
def calculate_min_distance(cur, arr):
    min_dis = 200
    for a in arr:
        dis = abs(a[0]-cur[0]) + abs(a[1]-cur[1])
        min_dis = min_dis if dis > min_dis else dis
    return min_dis

n, m = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(n)]

house, chicken = [], []
for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            house.append([i, j])
        elif city[i][j] == 2:
            chicken.append([i, j])

ans = 10000
for case in itertools.combinations(chicken, m):
    all_dis = 0
    for h in house:
        all_dis += calculate_min_distance(h, case)
    ans = ans if all_dis > ans else all_dis

print(ans)