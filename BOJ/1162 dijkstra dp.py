import heapq
import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
net = [[] for _ in range(N)]
for _ in range(M):
    t = list(map(int, input().split()))
    net[t[0]-1].append([t[1]-1, t[2]])
    net[t[1]-1].append([t[0]-1, t[2]])
    
heap = []
dis = [ [sys.maxsize for _ in range(K+1)] for _ in range(N)]
heapq.heappush(heap, (0, 0, K))
dis[0][K] = 0

while heap:
    cost, present, cnt = heapq.heappop(heap)
    for node, c in net[present]:
        if cnt > 0:
            # 포장할 수 있는 기회가 남았다?
            if dis[node][cnt-1] > cost:
                dis[node][cnt-1] = cost
                heapq.heappush(heap, (cost, node, cnt-1))
                
        new_w = cost + c
        if dis[node][cnt] > new_w:
            dis[node][cnt] = new_w
            heapq.heappush(heap, (new_w, node, cnt))
            
ans = sys.maxsize
for value in dis[N-1]:
    ans = min(ans, value)
print(ans)