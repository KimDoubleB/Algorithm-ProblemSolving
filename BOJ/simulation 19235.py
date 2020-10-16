# 모노미노도미노

# 빨간색 4x4
# 파란색 4x6
# 초록색 6x4

# 사용블록은 1x1, 1x2, 2x1

# 빨간색 1, 1에 둔다?
    # 파란색 1, x (왼쪽에서 훑으며)
    # 초록색 x, 1 (위에서 훑으며)
    # 에 들어가게 된다.
# 놓을 수 없다면 쌓이게 된다.

# 파란색: 한 열이 다 쌓이면
# 초록색: 한 행이 다 쌓이면
# 한 줄 다 사라지며, 1점을 얻는다.
# 동시에 한 열, 한 행이 사라지면 1점, 1점해서 2점을 얻는다
# 사라지면서
    # 파란색: 왼쪽에 남는 블록들
    # 초록색: 위에 남는 블록들
# 은 바닥을 다시 움직이게 되고, 이게 다시 한 줄을 채울 경우, 점수를 다시 얻는다. 즉, 이게 한 줄을 채우지 않을 때까지 반복한다.

# 특이하게도
    # 파란색: 0열, 1열
    # 초록색: 0행, 1행
# 에 블록이 쌓이게 되면, 쌓인만큼 아래로 내려간다. 즉, 1열 및 1행에 블록이 들어오면 파란색/초록색의 반대쪽 맨 끝 열/행이 없어지면서 모든 데이터가 한칸씩 이동한다.

# 행/열이 타일로 가득 찬 경우와 0/1 행/열에 블록이 찬 경우가 둘다 발생할 수 있다.
    # 먼저, 타일로 가득 찬 경우를 해결하고 (점수계산), 그 후 0/1 행/열에 대해 처리한다.

# (빨간색에) 블록을 놓는 위치가 순서대로 주어졌을 때, 얻은 점수와 초록색 및 파란색 보드에 있는 타일의 개수를 모두 구해라.

from collections import deque

# debugging
def pprint():
    print('-' * 15)
    for i in range(len(blue)):
        print(blue[i])

    print('*' * 10)

    for i in range(len(green)):
        print(green[i])

    print('*' * 10)

    print(score, block_num)


def line_breaker(board, green_or_blue):
    global score, block_num
    is_changed = True
    while is_changed:
        is_changed = False
        for i in range(len(board)):
            current_line = board.popleft()
            if sum(map(lambda x: x[1], current_line)) != 4:
                board.append(current_line)
            else:
                score, block_num = score+1, block_num-4
                is_changed = True
        if is_changed:
            for j in range(4):
                for i in range(len(board)-1, 0, -1):
                    if board[i][j][1] == 0:
                        for z in range(1, i+1):
                            if board[i-z][j][1] == 1:
                                if board[i-z][j][0] == green_or_blue and j != 3:
                                    if board[i][j+1][1] == 0 and board[i-z][j+1][1] == 1:
                                        board[i][j+1] = board[i-z][j+1]
                                        board[i-z][j+1] = [0, 0]
                                    else:
                                        break
                                board[i][j] = board[i-z][j]
                                board[i-z][j] = [0, 0]
                                break
    while len(board) < 6:
        board.appendleft([[0,0]] * 4)

def line_zero_one_checker(board):
    global block_num
    i = 0
    if sum(map(lambda x: x[1], board[0])) > 0:
        i = 2
    elif sum(map(lambda x: x[1], board[1])) > 0:
        i = 1
    for _ in range(i):
        block_num -= sum(map(lambda x: x[1], board.pop()))
        board.appendleft([[0,0]] * 4)

# input
N = int(input())
blue = deque([[0,0]] * 4  for _ in range(6))
green = deque([[0,0]] * 4 for _ in range(6))
block_info_list = [list(map(int, input().split())) for _ in range(N)]
score, block_num = 0, 0

for block_info in block_info_list:
    blue_not_install, green_not_install = True, True
    t, r, c = block_info
    # install
    if t == 1:
        # 1x1
        block_num += 2
        for i in range(2, 7):
            if blue_not_install and (i == 6 or blue[i][r][1] == 1):
                blue_not_install = False
                blue[i-1][r] = [t, 1]
            if green_not_install and (i == 6 or green[i][c][1] == 1):
                green_not_install = False
                green[i-1][c] = [t, 1]

    elif t == 2:
        # 1x2
        block_num += 4
        for i in range(2, 7):
            if blue_not_install and (i == 6 or blue[i][r][1] == 1):
                blue_not_install = False
                blue[i-1][r] = blue[i-2][r] = [t, 1]
            if green_not_install and (i == 6 or green[i][c][1] == 1 or green[i][c+1][1] == 1):
                green_not_install = False
                green[i-1][c] = green[i-1][c+1] = [t, 1]
    else:
        # 2x1
        block_num += 4
        for i in range(2, 7):
            if blue_not_install and (i==6 or blue[i][r][1] == 1 or blue[i][r+1][1] == 1):
                blue_not_install = False
                blue[i-1][r] = blue[i-1][r+1] = [t, 1]
            if green_not_install and (i==6 or green[i][c][1] == 1):
                green_not_install = False
                green[i-1][c] = green[i-2][c] = [t, 1]
    # Line calculation
    line_breaker(blue, 3)
    line_breaker(green, 2)

    # 0/1 row/column moving
    line_zero_one_checker(blue)
    line_zero_one_checker(green)

print(score)
print(block_num)
