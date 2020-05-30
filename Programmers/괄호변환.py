def is_balance(string):
    cnt = 0
    for s in string:
        if s == '(':
            cnt += 1
        else:
            cnt -= 1
    
    return True if cnt == 0 else False

def is_right(string):
    cnt = 0
    for s in string:
        if cnt < 0:
            return False
        if s ==')':
            cnt -= 1
        else:
            cnt += 1
    
    return True if cnt == 0 else False


def reverse(string):
    res = ""
    for s in string:
        if s =='(':
            res += ')'
        else:
            res += '('
    return res
    
    
def divide(w):
    u = ""
    while w:
        u, w = u+w[0], w[1:]
        if is_balance(u):
            break
    return u, w

def last_action(u, v):
    return '(' + v + ')' + reverse(u[1:len(u)-1])


def solution(w):
    if len(w) == 0:
        return ""
    u, v = divide(w)
    if is_right(u):
        return u + solution(v)
    else:
        v = solution(v)
        return last_action(u, v)
        
        
# def solution(p):
#     if len(p) == 0:
#         return ""
    
#     u, v = divide(p)
#     if is_right(u):
#         solution(v)
#     else:
        
    
#     answer = ''
#     return answer