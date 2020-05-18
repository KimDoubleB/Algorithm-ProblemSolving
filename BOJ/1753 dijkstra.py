import heapq
import sys
input = sys.stdin.readline

v, e = map(int, input().split())
net = [[] for _ in range(v)] 
k = int(input())
for _ in range(e):
    t = list(map(int, input().split()))
    net[t[0]-1].append([t[1]-1, t[2]])

MAX_COST = 10*e+1 # INF
heap = []
dis = [MAX_COST] * v 

heapq.heappush(heap, (0, k-1))
dis[k-1] = 0

while heap:
    cost, present = heapq.heappop(heap)
    for node, c in net[present]:
        # 근접 노드 순회
        # cost 제외
        new_w = cost + c
        if new_w >= dis[node]: 
            continue
        else:
            dis[node] = new_w
            heapq.heappush(heap, (new_w, node))
        
for v in dis:
    print(v if v < MAX_COST else 'INF')