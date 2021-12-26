def main():
    N = int(input())
    print(2*N-2)
    for i in range(2, N+1):
        print(i, end=' ')
    for i in range(N, 1, -1):
        print(i, end=' ')
    print('')

if __name__ == '__main__':
    main()
