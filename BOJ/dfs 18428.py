import sys
input = sys.stdin.readline
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
isVisible = True

def check_teacher_vision(teacher):
    danger = []
    for t in teacher:
        x, y = t[0], t[1]
        need_block = []
        for i in range(4):
            nx, ny = x, y
            temp_block = []
            while 1:
                nx, ny = nx+dx[i], ny+dy[i]
                if not (0 <= nx < n and 0 <= ny < n):
                    break
                if hallway[nx][ny] in ('T', 'O'):
                    break
                elif hallway[nx][ny] == 'S':
                    need_block.extend(temp_block)
                else:
                    temp_block.append((nx, ny))
        danger.extend(need_block)
    return list(set(danger))
            

def meet_student(teacher):
    for t in teacher:
        x, y = t[0], t[1]
        for i in range(4):
            nx, ny = x, y
            while 1:
                nx, ny = nx+dx[i], ny+dy[i]
                if not (0 <= nx < n and 0 <= ny < n):
                    break
                if hallway[nx][ny] in ('T', 'O'):
                    break
                elif hallway[nx][ny] == 'S':
                    return True
    return False

def install_block(cnt, ind):
    global isVisible
    if not isVisible:
        return
    if cnt == 3 or ind == len(danger):
        meet = meet_student(teacher)
        if not meet:
            isVisible = False
        return
    
    for d in range(ind, len(danger)):
        if hallway[danger[d][0]][danger[d][1]] == 'O':
            continue
        hallway[danger[d][0]][danger[d][1]] = 'O'
        install_block(cnt+1, ind+1)
        hallway[danger[d][0]][danger[d][1]] = 'X'

n = int(input())
hallway, teacher, danger = [], [], []
for i in range(n):
    hallway.append(list(input().split()))
    for j in range(n):
        if hallway[i][j] == 'T':
            teacher.append((i, j))

danger = check_teacher_vision(teacher)
install_block(0, 0)

print('NO' if isVisible else 'YES')