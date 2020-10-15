# # 제일 왼쪽에서 시작 -> 제일 오른쪽 끝

# # 오른쪽으로 한 칸 이동
# # 낚시왕 열에서 땅과 제일 가까운 상어 잡는다. -> 상어 없어짐
# # 상어가 이동
#     # - 상어는 칸/초 이동
#     # - 격자판 경계넘는 경우, 속력은 유지한채 방향 반대로 수행
# # 이동했는데, 한칸에 상어 2마리인 경우, 크기가 큰 상어만 남는다.
# # 낚시왕이 잡은 상어 크기의 합을 구하라

# # R, C, M (row / column / shark number)
# # M개줄
# # r, c, s, d, z (row/column/속력/이동방향/크기)
# # 1 위, 2 아래, 3 오른쪽, 4 왼쪽
import sys
input = sys.stdin.readline

R, C, M = map(int, input().split())
shark = [[[] for _ in range(C)] for _ in range(R)]
for _ in range(M):
    r, c, s, d, z = map(int, input().split())
    if d == 1:
        d = [-1, 0]
    elif d == 2:
        d = [1, 0]
    elif d == 3:
        d = [0, 1]
    elif d == 4:
        d = [0, -1]
    shark[r-1][c-1] = [s, d, z]

shark_weight = 0
for fisher in range(C):
    # 물고기 잡기
    for k in range(R):
        if len(shark[k][fisher]) > 0:
            shark_weight += shark[k][fisher][2]
            shark[k][fisher] = []
            break

    # 상어 이동
    after = [[[] for _ in range(C)] for _ in range(R)]
    for i in range(R):
        for j in range(C):
            cur_shark = shark[i][j]
            if len(cur_shark) == 0:
                continue

            dx, dy = cur_shark[1][0] * cur_shark[0], cur_shark[1][1] * cur_shark[0]
            nx, ny = i + dx, j + dy

            while True:
                if nx < 0:
                    nx = -nx
                    cur_shark[1][0] = 1
                elif nx >= R:
                    nx = 2*R-2-nx
                    cur_shark[1][0] = -1
                elif ny < 0:
                    ny = -ny
                    cur_shark[1][1] = 1
                elif ny >= C:
                    ny = 2*C-2-ny
                    cur_shark[1][1] = -1
                if 0 <= nx < R and 0 <= ny < C:
                    break
            
            if len(after[nx][ny]) > 0 and after[nx][ny][2] > cur_shark[2]:
                continue
            after[nx][ny] = cur_shark
    shark = after

print(shark_weight)

# -------------------------------------------------------
# 다른 방법론: 상어 위치를 저장하고 활용하자 !
# import sys
# from collections import deque
# input = sys.stdin.readline

# R, C, M = map(int, input().split())
# sharks = deque()
# sea = [[0] * C for _ in range(R)]
# for _ in range(M):
#     r, c, s, d, z = map(int, input().split())
#     if d == 1:
#         d = [-1, 0]
#     elif d == 2:
#         d = [1, 0]
#     elif d == 3:
#         d = [0, 1]
#     elif d == 4:
#         d = [0, -1]
#     sharks.append([r-1, c-1, s, d, z])
#     sea[r-1][c-1] = z

# shark_weight = 0
# die_shark = []
# for fisher in range(C):
#     print('----------')
#     print(shark_weight)
#     print(sharks)
#     # 물고기 잡기
#     for k in range(R):
#         if sea[k][fisher] > 0:
#             shark_weight += sea[k][fisher]
#             die_shark.append(sea[k][fisher])
#             break

#     sea = [[0] * C for _ in range(R)]

#     for _ in range(len(sharks)):
#         shark = sharks.popleft()
#         if shark[4] in die_shark:
#             continue
#         dx, dy = shark[3][0] * shark[2], shark[3][1] * shark[2]
#         nx, ny = shark[0] + dx, shark[1] + dy

#         while True:
#             if nx < 0:
#                 nx = -nx
#                 shark[3][0] = 1
#             elif nx >= R:
#                 nx = 2*R-2-nx
#                 shark[3][0] = -1
#             elif ny < 0:
#                 ny = -ny
#                 shark[3][1] = 1
#             elif ny >= C:
#                 ny = 2*C-2-ny
#                 shark[3][1] = -1
#             if 0 <= nx < R and 0 <= ny < C:
#                 break

#         if shark[4] > sea[nx][ny]:
#             if sea[nx][ny] != 0:
#                 die_shark.append(sea[nx][ny])
#             sea[nx][ny] = shark[4]
#             sharks.append(shark)
#         else:
#             die_shark.append(sea[nx][ny])

# print(shark_weight)
