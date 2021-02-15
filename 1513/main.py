import sys
from collections import deque

def main():
    N, K = map(int, input().split())

    dp = deque()
    dp.append(1)
    dp.append(1)
    for i in range(2, K+2):
        dp.append(dp[-1] << 1)
    for i in range(K+2, N+2):
        dp.append((dp[-1] << 1)-dp.popleft())

    result = 0
    for i in range(1, K+2):
        result += dp[-1-i]
    print(result)

if __name__ == '__main__':
    main()
