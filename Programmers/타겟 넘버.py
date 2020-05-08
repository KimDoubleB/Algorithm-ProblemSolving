cnt = 0
def dfs(val, index, num, target):
    global cnt    
    if len(num) == index:
        if val == target:
            cnt+=1
        return
    
    dfs(val + num[index], index+1, num, target)
    dfs(val - num[index], index+1, num, target)

def solution(num, target):
    global cnt
    
    dfs(0, 0, num, target)
    
    return cnt