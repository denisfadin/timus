import sys

def main():
    N, K = map(int, input().split())

    dp = [0]*(N+2)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, K+2):
        dp[i] = dp[i-1] << 1
    for i in range(K+2, N+1):
        dp[i] = (dp[i-1] << 1) - dp[i-K-2]

    result = 0
    for i in range(0, K+1):
        result += dp[N-i]
    print(result)

if __name__ == '__main__':
    main()
