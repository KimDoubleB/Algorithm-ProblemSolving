import math

def solution(n, k):
    ans = []
    val = list(range(1, n+1))
    fac = math.factorial(n);
    k -= 1 # 인덱스 조정, 1인 경우 생각
    
    while(n > 0):
        fac /= n
        ans.append(val.pop(int(k/fac)))
        n -= 1
        k %= fac
    
    return ans