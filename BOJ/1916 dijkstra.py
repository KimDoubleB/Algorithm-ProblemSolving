import heapq
import sys
input = sys.stdin.readline

v = int(input())
e = int(input())
net = [[] for _ in range(v)]
for _ in range(e):
    t = list(map(int, input().split()))
    net[t[0]-1].append([t[1]-1, t[2]])
start, end = map(int, input().split())


MAX_COST = 100000*e+1
heap = []
dis = [MAX_COST] * v

heapq.heappush(heap, (0, start-1))
dis[start-1] = 0

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
        
print(dis[end-1])