import heapq

n = int(input())

cards = []
for _ in range(n):
    heapq.heappush(cards, int(input()))

cnt = 0
while cards:
    if len(cards) == 1:
        break
    
    val = heapq.heappop(cards) + heapq.heappop(cards)
    heapq.heappush(cards, val)
    cnt += val
    
print(cnt)