n = int(input())
mapmap = []
for _ in range(n):
    mapmap.append(list(map(int, input().split())))
island = []

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 섬마다 해안가 데이터만 뽑아옴
def dfs():
    st = []
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and mapmap[i][j] == 1:
                island.append([])
                st.append([i,j])
                visited[i][j] = True
                while len(st):
                    pt = st.pop()
                    near_sea = False
                    for k in range(4):
                        nx, ny = pt[0]+dx[k], pt[1]+dy[k]
                        if nx < 0 or ny < 0 or nx >= n or ny >= n:
                            continue
                        
                        if mapmap[nx][ny] < 1:
                            # 바다?
                            near_sea = True
                            continue
                            
                        if not visited[nx][ny]:
                            # 육지?
                            st.append([nx, ny])
                            visited[nx][ny]=True
                    if near_sea:
                        island[-1].append(pt)
                
dfs() 
bridge = 200

# 해안가끼리 비교 >> 최소값
def calculate(num):
    global bridge
    near_sea = []
    for i, v in enumerate(island):
        if i != num:
            near_sea += v

    for v1 in island[num]:
        for v2 in near_sea:
            diff = abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]) - 1
            if diff < bridge: bridge = diff

for i in range(len(island)):
    calculate(i)
print(bridge)