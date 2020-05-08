def solution(prices):
    answer = [0 for _ in prices]
    for i in range(len(prices)):
        for j in range(i+1, len(prices)):
            answer[i] += 1 # 시간 증가

            # 가격이 떨어졌으면, 종료
            if prices[i] > prices[j]:
                break
    return answer