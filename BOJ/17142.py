# 시간초과

# 바이러스 활성과 비활성상태
# 처음 모든 바이러스는 비활성
# 활성 바이러스는 상하좌우 인접 모든 빈 칸으로 동시 복제, 1초마다
# 바이러스 M개를 활성상태로 변경하려함

# NxN 연구소
# 빈칸 (0), 벽 (1), 바이러스 놓을 수 있는 위치 (2)
# 2의 개수는 M보다 크거나 같고, 10보다 작은 자연수
# 활성 바이러스가 비활성 바이러스로 가면 활성으로 바뀐다.

# 모든 빈칸에 바이러스를 퍼뜨리는 최소시간을 구해라.
# 바이러스를 어떻게 놓아도 모든 빈칸에 바이러스를 퍼뜨릴 수 없는 경우 -1
from itertools import combinations
from collections import deque

# # 이거 필요 없다.
# def is_virus_all_spread():
#     max_val, is_right = -999, True
#     for i in range(n):
#         for j in range(n):
#             if visited[i][j] != -1 or lab[i][j] == 1 or lab[i][j] == 2:
#                 max_val = max_val if max_val >= visited[i][j] else visited[i][j]
#             else:
#                 is_right = False
#     return max_val, is_right

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
n, m = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(n)]

can_virus = []
for i in range(n):
    for j in range(n):
        if lab[i][j] == 2:
            can_virus.append((i, j))

virus_order = combinations(can_virus, m)
min_time = -1
for viruses in virus_order:
    visited = [[-1] * n for _ in range(n)]
    q = deque()
    for virus in viruses:
        q.append(virus)
        visited[virus[0]][virus[1]] = 0
    while q:
        # 이걸 할 필요가 없다.
        spread_time, is_all_spread = is_virus_all_spread()

        # 감염 바이러스 개수 = 빈칸의 개수 (0) 이면 종료된 것
        # - 빈칸의 수 카운트 했어야 함
        # 마지막 감염 된 빈칸의 visited 값이 최대 시간인 것

        if is_all_spread:
            # 다 퍼짐
            if min_time < 0:
                min_time = spread_time
            else:
                min_time = min_time if spread_time >= min_time else spread_time
            break
        else:
            if min_time != -1 and spread_time >= min_time:
                break
            # 아직 다 안퍼졌다.
            cur_virus = q.popleft()
            for i in range(4):
                nx, ny = cur_virus[0] + dx[i], cur_virus[1] + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] >= 0:
                    continue
                visited[nx][ny] = visited[cur_virus[0]][cur_virus[1]] + 1
                if lab[nx][ny] == 1:
                        continue
                q.append((nx, ny))
            
print(min_time)