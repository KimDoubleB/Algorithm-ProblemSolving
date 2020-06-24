# 보배
import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    cnt = 0
    while True:
        f1 = heapq.heappop(scoville)
        if f1 >= K:
            return cnt
        else:
            if len(scoville) == 0:
                break
            f2 = heapq.heappop(scoville)
            heapq.heappush(scoville, f1 + f2*2)
            cnt += 1
    return -1