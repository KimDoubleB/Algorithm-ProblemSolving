def solution(dirs):
    visited = [[[False, False, False, False] for _ in range(15)] for _ in range(15)]
    cur = [0, 0]
    cnt = 0
    for ch in dirs:
        if ch=='U':
            dx, dy, dr1, dr2 = 0, 1, 0, 1
        elif ch =='D':
            dx, dy, dr1, dr2 = 0, -1, 1, 0
        elif ch == 'L':
            dx, dy, dr1, dr2 = -1, 0, 2, 3
        else:
            dx, dy, dr1, dr2 = 1, 0, 3, 2
                        
        nx, ny = dx+cur[0], dy+cur[1]
        if nx>5 or nx<-5 or ny>5 or ny<-5:
            continue
        
        if not visited[nx][ny][dr1] and not visited[cur[0]][cur[1]][dr2]:
            visited[nx][ny][dr1] = True
            visited[cur[0]][cur[1]][dr2] = True
            cnt+=1
        cur = [nx, ny]
        
    return cnt