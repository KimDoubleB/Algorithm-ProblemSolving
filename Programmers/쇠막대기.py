def solution(arr):
    arr = arr.replace('()', 'R')
    ans, f = 0, 0
    for v in arr:
        if v == '(':
            f+=1
        elif v == 'R':
            ans +=f
        else:
            ans += 1
            f -= 1
    return ans