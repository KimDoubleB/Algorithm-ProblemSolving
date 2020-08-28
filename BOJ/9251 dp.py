s1, s2 = input(), input()
dp = [[0] * (len(s2)+1) for i in range(len(s1) + 1)]
for i in range(len(s1)):
    for j in range(len(s2)):
        if(s1[i] == s2[j]):
            dp[i+1][j+1] = dp[i][j] + 1
        else:
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
print(dp[-1][-1])