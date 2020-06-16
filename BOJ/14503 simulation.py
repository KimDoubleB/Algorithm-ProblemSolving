import sys
input = sys.stdin.readline

n, m = map(int, input().split())
x, y, d = map(int, input().split())
mapp = [list(map(int, input().split())) for _ in range(n)]
dx, dy = (-1, 0, 1, 0), (0, 1, 0, -1)

mapp[x][y] = 2
def solution(x, y, d, ans):
    while True:
        c = False
        for k in range(4):
            d = (d + 3) % 4
            nx, ny = x+dx[d], y+dy[d]
            if not mapp[nx][ny]:
                # 청소
                mapp[nx][ny] = 2
                ans += 1
                x, y = nx, ny
                c = True
                break
        if not c:
            if mapp[x-dx[d]][y-dy[d]] == 1:
                # 후진불가?
                return ans
            else:
                x, y = x-dx[d], y-dy[d]

print(solution(x, y, d, 1))