# N x N 땅
# 각각의 칸은 (r, c)로 나타낸다, 1부터 시작

# S2D2 양분조사, 처음에 양분 모든 땅에 5만큼 존재

# 나무재테크 - 작은 묘목 키워서 팜
# M개의 나무 구매

# 봄 - 자신의 나이 만큼 현재 땅의 양분을 먹고, 나이가 1 증가
#   - 하나의 칸에 여러 나무가 있을 수 있으며, 나이가 어린 나무부터 양분을 먹는다.
#   - 만약 자신의 나이만큼 양분이 없다면, 즉시 죽는다.

# 여름 - 봄에 죽은 나무가 양분이 됨.
#   - 죽은 나무의 나이를 2로 나눈 값이 나무의 칸에 양분으로 추가
#   - 소숫점 아래는 버린다. (int)

# 가을 - 나이가 5의 배수인 나무가 번식
#   - 번식은 인접한 8개의 칸에 나이가 1인 나무가 생김

# 겨울 - S2D2가 땅을 돌아다니며 양분을 추가한다. 
#   - A[r][c] 만큼 추가하며, 입력으로 주어진다.

# K년 뒤의 땅에 살아있는 나무의 개수를 구해라

# N, M, K : 땅 크기, 나무 개수, 종료 년
# N줄, A[r][c] 배열 주어짐 : S2D2가 추가하는 양분
# M줄, 나무 정보 x y z : 나무의 위치, 나무의 나이
import sys
from collections import deque
input = sys.stdin.readline

dx, dy = [-1, -1, -1, 0, 0, 1, 1 ,1], [-1, 0, 1, -1, 1, -1, 0, 1]
tree_count = 0

N, M, K = map(int, input().split())
A = [ list(map(int, input().split())) for _ in range(N) ]
trees = [[deque() for _ in range(N)] for _ in range(N)]
soil = [[5] * N for _ in range(N)]

# x-1, y-1 동기화
for _ in range(M):
    x, y, z = map(int, input().split())
    trees[x-1][y-1].append(z)
    tree_count += 1

while K:
    # 봄, 여름
    for i in range(N):
        for j in range(N):
            tree = trees[i][j]
            for k in range(len(tree)):
                if soil[i][j] >= tree[k]:
                    soil[i][j] -= tree[k]
                    tree[k] += 1
                else:
                    while k < len(tree):
                        soil[i][j] += (tree.pop()//2)
                        tree_count -= 1
                    break

    # 겨울, 가을
    for i in range(N):
        for j in range(N):
            tree = trees[i][j]
            for k in range(len(tree)):
                if tree[k] % 5 == 0:
                    for d in range(8):
                        nx, ny = i + dx[d], j + dy[d]
                        if nx < 0 or nx >= N or ny < 0 or ny >= N:
                            continue
                        trees[nx][ny].appendleft(1)
                        tree_count += 1
            soil[i][j] += A[i][j]
    K -= 1

print(tree_count)