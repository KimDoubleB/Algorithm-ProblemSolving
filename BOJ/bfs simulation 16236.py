# nxm
# m마리 물고기, 1마리 상어
# 처음 아기상어 크기 2, 1초에 상하좌우 이동

# 자신의 크기보다 큰 물고기 있으면 못지나감, 나머지 칸은 이동 가능
# 자신의 크기보다 작은 물고기만 먹고, 지나갈 수 있다.
# 자신의 크기와 같은 물고기면, 지나가기만 가능

# 아기 상어
# - 더이상 먹을 수 있는 물고기 없다?
    # - 엄마 상어 도움
# - 먹을 수 있는 물고기 1마리?
    # - 그 물고기 먹으러간다.
# - 먹을 수 있는 물고기가 1마리보다 많다?
    # - 가장 가까운 물고기 먹으러간다. -> 지나가야하는 칸의 개수 최소
    # - 거리가 가까운 물고기가 여러개라면, 가장 위, 왼쪽에 있는 물고기를 먹는다.

# 아기상어 이동 1초, 물고기먹으면 그 칸은 빈칸
# 아기상어는 자신의 크기와 같은 수의 물고기 (크기 = 먹은 수)를 먹을 때마다 크기가 1 증가

# 아기상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고, 물고기를 잡아먹을 수 있는가?
# 즉, 엄마 상어를 부르기까지 몇 초가 걸리는가?

# 0: 빈칸
# 9: 아기상어
# 1 ~ 6: 물고기 (크기)

from collections import deque

def find_shark():
    for i in range(n):
        for j in range(n):
            if sea[i][j] == 9:
                sea[i][j] = 0
                shark = (i, j)
                return shark

def find_fish_shark(shark_size):
    fish = []
    for i in range(n):
        for j in range(n):
            if shark_size > sea[i][j] >= 1:
                fish.append((i, j)) # 크기, x, y
    return fish

def eat_fish(shark, size):
    visited = [[False] * n for _ in range(n)]
    eat_fish_member = []
    
    q = deque()
    q.append([shark, 0])
    visited[shark[0]][shark[1]] = True
    min_distance = 99999
    
    while q:
        cur_shark, distance = q.popleft()
        if distance > min_distance:
            continue

        # 먹을 수 있는 경우
        if size > sea[cur_shark[0]][cur_shark[1]] >= 1:
            min_distance = distance
            eat_fish_member.append([cur_shark, distance])
        for i in range(4):
            nx, ny = cur_shark[0] + dx[i], cur_shark[1] + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or sea[nx][ny] > size:
                continue
            q.append([(nx,ny), distance+1])
            visited[nx][ny] = True

    eat_fish_member = sorted(eat_fish_member, key=lambda x: (x[0][0], x[0][1]))
    if len(eat_fish_member) > 0:
        die_fish = eat_fish_member[0][0]
        sea[die_fish[0]][die_fish[1]] = 0
        return min_distance, die_fish
    else:
        return -1, -1

dx, dy = [-1, 0, 0, 1], [0, -1, 1, 0]
n = int(input())
sea = [list(map(int, input().split())) for _ in range(n)]
shark = find_shark()

shark_size = 2
eat_cnt, time = 0, 0
while 1:
    fish = find_fish_shark(shark_size)
    if len(fish) == 0:
        break
    else:
        distance, shark = eat_fish(shark, shark_size)
        if distance < 0:
            break
        eat_cnt, time = eat_cnt+1, time+distance
        if eat_cnt == shark_size:
            eat_cnt, shark_size = 0, shark_size+1

print(time)