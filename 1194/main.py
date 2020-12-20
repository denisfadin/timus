import sys

N, K = map(int, input().split())

print((((N - 1) * N) >> 1) - K)
