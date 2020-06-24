# 보배
import collections

def solution(length, weight, truck):
    dq = collections.deque([[0, 0]]) # 시간, 인덱스
    time, ind = 1, 1
    all_weight = truck[0]
    while dq:
        if ind == len(truck):
            # 트럭 다 들어감
            last = dq.pop()
            time = length + last[0]
            break
            
        if time - dq[0][0] == length:
            out = dq.popleft()
            all_weight -= truck[out[1]]
            
        if weight >= truck[ind] + all_weight:
            dq.append([time, ind])
            all_weight += truck[ind]
            ind += 1
            time += 1
        else:
            time = dq[0][0] + length
    return time+1