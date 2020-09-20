import sys
input = sys.stdin.readline

n = int(input())
num = list(map(int, input().split()))
operand = list(map(int, input().split()))

min_val, max_val = sys.maxsize, -sys.maxsize-1

def calculator(i, val1, val2):
    if i == 0:
        return val1+val2
    elif i == 1:
        return val1-val2
    elif i == 2:
        return val1*val2
    elif i == 3:
        if val1 < 0 and val2 > 0:
            return abs(val1)//val2 * -1
        return val1//val2


def dfs(opers, cur, ind):
    global min_val, max_val
    if ind == len(num):
        max_val = cur if cur > max_val else max_val
        min_val = cur if min_val > cur else min_val
        return
    for i, op in enumerate(opers):
        if not op:
            continue
        new_cur = calculator(i, cur, num[ind])
        opers[i] -= 1
        dfs(opers, new_cur, ind+1)
        opers[i] += 1
    
dfs(operand, num[0], 1)
print(max_val)
print(min_val)

