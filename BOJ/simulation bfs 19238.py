# 스타트 택시
# 도착지로 데려다줄때마다 연료 충전, 연료바닥나면 업무종료

# M명의 승객 목표, NxN 영역
# 벽 또는 빈칸 -> 택시는 상하좌우 빈칸으로 이동가능
# 특정위치 이동시, 최단경로로만 이동

# 승객은 목적지가 따로 있다.
# 승객을 목적지로 데려다 줘야하는 것을 M번 반복
# 동시에 못태움

# 현재위치에서 최단거리의 승객 고름
# 그런 승객이 많으면, 행/열 번호 순으로 고름
# 같은위치면 최단거리 0
# 연료는 이동시 1만큼 소모, 
#   목적지로 이동 성공하면 승객 태워 소모한 연료 양의 두배가 충전
#   태우러 간 거리는 미포함인듯
# 도중에 연료 바닥나면, 업무 종료
# 목적지 도착 동시에 연료가 바닥나는 경우는 실패한 것으로 간주X

# 모든 승객을 성공적으로 데려다줄 수 있는지 알아내고,
# 데려다 줄 수 있는 경우 남는 연료양을 출력

# 모든 승객을 이동 못시키거나, 연료가 도중 바닥난 경우, -1 출력

# == 벽으로 손님이 가려진 경우도 생각
# == 벽으로 목적지가 가려진 경우도 생각

# 연료양 무한충전 가능, 초기연료 넘을 수 있다.
from collections import deque
MAX_VAL = 99999
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
def bfs(first, target):
    visited = [[-1] * N for _ in range(N)]
    min_diff, min_diff_customer = -1, []
    q = deque()
    q.append(first)
    visited[first[0]][first[1]] = 0
    while q:
        cur = q.popleft()
        if min_diff >= 0 and visited[cur[0]][cur[1]] > min_diff:
            continue
        if chart[cur[0]][cur[1]] > target:
            min_diff_customer.append(cur)
            min_diff = visited[cur[0]][cur[1]]
            continue
        for i in range(4):
            nx, ny = cur[0]+dx[i], cur[1]+dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= N or chart[nx][ny] == 1 or visited[nx][ny] >= 0:
                continue
            q.append([nx, ny])
            visited[nx][ny] = visited[cur[0]][cur[1]] + 1
    dest = [MAX_VAL, MAX_VAL]
    for cus in min_diff_customer:
        if dest[0] > cus[0]:
            dest = cus
        elif dest[0] == cus[0]:
            if dest[1] > cus[1]:
                dest = cus
    
    return dest, min_diff

def solve():
    global taxi, oil, M
    while M:
        # 승객 태우기
        taxi, used_oil = bfs(taxi, 1)
        if used_oil < 0 or used_oil > oil:
            return -1
        oil -= used_oil
        customer_ind = chart[taxi[0]][taxi[1]]
        chart[taxi[0]][taxi[1]] = 0
        target = customers[customer_ind-2]

        # 승객 이동
        temp_val = chart[target[0]][target[1]]
        chart[target[0]][target[1]] = MAX_VAL
        taxi, used_oil = bfs(taxi, MAX_VAL-1)
        chart[target[0]][target[1]] = temp_val
        if used_oil < 0 or used_oil > oil:
            return -1
        oil += used_oil
        
        M -= 1
    return oil
        
N, M, oil = map(int, input().split())
chart = [ list(map(int, input().split())) for _ in range(N)]
x, y = map(int, input().split())
taxi = [x-1, y-1]
customers = []
for i in range(M):
    x, y, tx, ty = map(int, input().split())
    chart[x-1][y-1] = i+2
    customers.append([tx-1, ty-1])

val = solve()
print(val)