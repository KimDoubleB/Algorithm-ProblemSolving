import sys
from itertools import combinations, permutations
input = sys.stdin.readline

def get_cost(values):
    c = 0
    permu = list(permutations(values, 2))
    for p in permu:
        c += cost[p[0]-1][p[1]-1]
    return c 

n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]

num = [i for i in range(1, n+1)]
num_list = list(combinations(num, int(n/2)))
diff_min = 10000
for one_team in num_list:
    two_team = tuple(n for n in num if not n in one_team)
    c1, c2 = get_cost(one_team), get_cost(two_team)
    diff_min = abs(c1-c2) if diff_min > abs(c1-c2) else diff_min

print(diff_min)