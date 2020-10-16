# 체스판과 새로운 게임
# NxN, 말 K개 (1~K 번호, 이동방향)
#   - 말 위에 다른 말을 올릴 수 있다.
#   - 상하좌우
#   - 1: 우, 2: 좌, 3: 상, 4: 하

# 턴 한번에 1번 말부터 순서대로 이동
# 한 말이 이동할 때 올려져 있는 말도 같이 이동
# 이동방향에 있는 칸에 따라 말의 이동이 다름
# 말이 4개가 쌓이는 순간 게임 종료

# 이동하려는 칸 (0: 흰색, 1: 빨간색, 2: 파란색)
# 흰색인 경우?
    # 그 칸으로 이동
    # 말이 이미 있는 경우, A번 말 위에 올려놓는다.
    # 이동 칸 말 + 현재 말
# 빨간색인 경우?
    # 현재 말들의 순서를 바꾼다
    # 이동 칸 말 + 현재 말(reverse)
# 파란색이거나, 체스판을 벗어나는 경우?
    # A번 말의 이동방향을 반대로하고 한 칸 이동
    # 반대로 한 칸 이동하려고하는데 파란색인경우? 그대로 존재

# 게임이 종료되는 턴의 번호를 출력
# 턴의 번호가 1000보다 크거나
# 절대로 게임이 종료되지 않는 경우, -1 출력 (이동이 없는 경우)

N, K = map(int, input().split())
chess_map = [ list(map(int, input().split())) for _ in range(N) ]
current_map = [[[] for _ in range(N)] for _ in range(N)]
pieces = []
for num in range(K):
    r, c, d = map(int, input().split())
    if d == 1:
        d = [0, 1]
    elif d == 2:
        d = [0, -1]
    elif d == 3:
        d = [-1, 0]
    else:
        d = [1, 0]
    current_map[r-1][c-1].append(num)
    pieces.append([r-1, c-1, d])

def solve():
    turn_count = 0
    is_moved = True

    while True:
        print(current_map)
        turn_count += 1
        if turn_count > 1000 or not is_moved:
            # 턴의 번호가 1000보다 크거나
            # 절대로 게임이 종료되지 않는 경우, -1 출력 (이동이 없는 경우)
            print(-1)
            return
        is_moved = False
        for num in range(K):
            current_piece = pieces[num]
            nx, ny = current_piece[0] + current_piece[2][0], current_piece[1] + current_piece[2][1]
            if nx < 0 or nx >= N or ny < 0 or ny >= N or current_map[nx][ny] == 2:
                current_piece[2][0] *= -1
                current_piece[2][1] *= -1
                nx, ny = current_piece[0] + current_piece[2][0], current_piece[1] + current_piece[2][1]
                if nx < 0 or nx >= N or ny < 0 or ny >= N or current_map[nx][ny] == 2:
                    continue
            is_moved = True
            current_position_pieces = current_map[current_piece[0]][current_piece[1]]
            for i, piece_num in enumerate(current_position_pieces):
                if num == piece_num:
                    stay, move = current_position_pieces[:i], current_position_pieces[i:]
            current_map[current_piece[0]][current_piece[1]] = stay
            for m in move:
                pieces[m][0], pieces[m][1] = nx, ny
            
            if len(current_map[nx][ny]) + len(move) >= 4:
                print(turn_count)
                return
            if chess_map[nx][ny] == 0:
                current_map[nx][ny].extend(move)
            elif chess_map[nx][ny] == 1:
                current_map[nx][ny].extend(reversed(move))
solve()
