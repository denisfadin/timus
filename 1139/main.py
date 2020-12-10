import sys

def GCF(N, M):
    for i in range(max(N, M), 0, -1):
        if N % i == 0 and M % i == 0:
            return i

def main():
    N, M = map(int, input().split())
    N -= 1
    M -= 1
    print( N + M - GCF(N, M) )

if __name__ == '__main__':
    main()
