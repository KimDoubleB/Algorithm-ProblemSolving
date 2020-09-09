import sys
input = sys.stdin.readline

tet = [[(0, 0), (0, 1), (0, 2), (0, 3)],
        [(0, 0), (1, 0), (2, 0), (3, 0)],
        [(0, 0), (0, 1), (1, 0), (1, 1)],
        [(0, 1), (1, 1), (2, 1), (2, 0)],
        [(0, 0), (1, 0), (2, 0), (2, 1)],
        [(0, 0), (0, 1), (0, 2), (1, 0)],
        [(0, 0), (1, 0), (1, 1), (1, 2)],
        [(0, 0), (0, 1), (1, 1), (2, 1)],
        [(0, 0), (0, 1), (1, 0), (2, 0)],
        [(0, 2), (1, 0), (1, 1), (1, 2)],
        [(0, 0), (0, 1), (0, 2), (1, 2)],
        [(0, 0), (1, 0), (1, 1), (2, 1)],
        [(1, 0), (0, 1), (1, 1), (0, 2)],
        [(0, 1), (1, 0), (1, 1), (2, 0)],
        [(0, 0), (0, 1), (1, 1), (1, 2)],
        [(0, 1), (1, 0), (1, 1), (1, 2)],
        [(0, 0), (1, 0), (1, 1), (2, 0)],
        [(0, 0), (0, 1), (0, 2), (1, 1)],
        [(0, 1), (1, 0), (1, 1), (2, 1)]
    ]

def solution():
    max_sum = 0
    for x in range(n):
        for y in range(m):
            for t in tet:
                cnt, can = 0, True
                for e in t:
                    nx, ny = e[0]+x, e[1]+y
                    if n > nx >= 0 and m > ny >= 0:
                        cnt += paper[nx][ny]
                    else:
                        can = False
                        break
                if can:
                    max_sum = cnt if cnt > max_sum else max_sum
    return max_sum                    


n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
print(solution())