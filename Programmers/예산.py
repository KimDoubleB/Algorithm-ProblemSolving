def solution(d, budget):
    d.sort()
    all_pass = True
    for i, v in enumerate(d):
        budget -= v
        if budget < 0: 
            all_pass= False
            break
    return i+1 if all_pass else i 
