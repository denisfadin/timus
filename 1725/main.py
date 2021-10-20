def main():
    N, K = map(int, input().split())
    if N == 2:
        print(0)
    else:
        if K > N / 2:
            K = N-K+1
        print(N-K-2)

if __name__ == '__main__':
    main()
