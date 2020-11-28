import sys

N, M = map(int, input().split())

if M < N:
    print(2*(M-1)+1)
else:
    print(2*(N-1))
