def solution(n, times):
    lo, hi = 1, max(times) * n 
    
    while(lo <= hi):
        people=0
        mid=(lo+hi)//2
        
        for t in times:
            people += mid//t
        
        if people < n:
            lo=mid+1
        else:
            hi=mid-1
            answer=mid
        
    return answer