def solution(n):
    fibo = [1, 2]
    while len(fibo) != n:
        fibo.append(fibo[-1]+fibo[-2])
    return 2 * (fibo[-1] + fibo[-2])