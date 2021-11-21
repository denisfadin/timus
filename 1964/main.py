def main():
    N, K = map(int, input().split())
    data = list(map(int, input().split()))
    result = N
    for i in range(K):
        result -= (N-data[i])
    if result < 0:
        result = 0
    print(result)

if __name__ == '__main__':
    main()
