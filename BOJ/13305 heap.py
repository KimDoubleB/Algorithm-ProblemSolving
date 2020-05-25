import heapq
import sys
input = sys.stdin.readline

city = int(input())
road = list(map(int, input().split()))
price = [0] * len(road)
oil = list(map(int, input().split()))
hq_oil = []

for i, v in enumerate(oil):
    heapq.heappush(hq_oil, (v, i))

while hq_oil:
    present = heapq.heappop(hq_oil)
    for i in range(present[1], city-1):
        if price[i] > 0:
            break
        price[i] = present[0]

all_price = 0
for i in range(city-1):
    all_price += (price[i] * road[i])
    
print(all_price)