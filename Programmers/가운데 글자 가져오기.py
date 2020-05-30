def solution(s):
    center = int(len(s)/2)
    if len(s)%2:
        # 홀수
        return s[center]
    else:
        # 짝수
        return s[center-1:center+1]