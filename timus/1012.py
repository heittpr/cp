n = int(input())
k = int(input())

dp = [0] * (n+1)
dp[0] = 1
dp[1] = k-1

for i in range(1, n+1):
    dp[i] = (k-1) * (dp[i-1] + dp[i-2])

print(dp[n])
