import heapq
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
net = [[] for _ in range(n)]
for _ in range(m):
    t1, t2 = map(int, input().split())
    net[t1-1].append(t2-1)
    net[t2-1].append(t1-1)

MAX_COST = 60000

heap = []
dis = [MAX_COST] * n # INF

heapq.heappush(heap, (0, 0))
dis[0] = 0

while heap:
    cost, present = heapq.heappop(heap)
    for node in net[present]:
        # 근접 노드 순회
        # cost 제외
        new_w = cost + 1
        if new_w >= dis[node]: 
            continue
        else:
            dis[node] = new_w
            heapq.heappush(heap, (new_w, node))


# print
max_dis = max(dis)
ans_num, ans_val, ans_cnt = -1, max_dis, 0

for i, v in enumerate(dis):
    if v == max_dis:
        if ans_num < 0:
            ans_num = i+1
        ans_cnt+=1
        
print(ans_num, ans_val, ans_cnt)