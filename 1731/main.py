import sys

def main():
    N, M = map(int, input().split())

    for i in range(N):
        print(i+1, end=' ')
    print()

    for i in range(M):
        print((i+1)*(N+1), end=' ')
    print()

if __name__ == '__main__':
    main()
