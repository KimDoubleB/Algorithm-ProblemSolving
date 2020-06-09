import math
def solution(p, s):
    ans, day = [], []
    for i in range(len(p)):
        day.append(math.ceil((100-p[i])/s[i]))
    now = -1
    for d in day:
        if now >= d:
            ans[-1] += 1
        else:
            now = d
            ans.append(1)
    return ans