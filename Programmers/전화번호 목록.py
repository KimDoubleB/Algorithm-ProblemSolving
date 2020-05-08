def solution(p):
    for val in p:
        p2 = p.copy()
        p2.remove(val)
        for val2 in p2:
            if val2.startswith(val):
                return False
    return True