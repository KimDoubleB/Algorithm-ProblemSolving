import sys
input = sys.stdin.readline

n, k = map(int, input().split())
cnt = [1] + [0 for _ in range(k)]

for _ in range(n):
    coin = int(input())
    for i in range(coin, k+1):
        # cnt[i-coin]에 이번 차례의 코인을 더하면
        # cnt[i]가 될 수 있으므로 경우의 수를 더해줌
        cnt[i] += cnt[i-coin]
        
print(cnt[k])
    