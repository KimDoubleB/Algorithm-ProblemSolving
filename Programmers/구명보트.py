# 보배
def solution(people, limit):
    people.sort()
    f, l, cnt = 0, len(people)-1, 0
    while f < l:
        if people[f] + people[l] > limit:
            l -= 1
        else:
            f, l = f+1, l-1
        cnt+=1
    return cnt if f != l else cnt+1