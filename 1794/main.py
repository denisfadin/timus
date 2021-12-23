def main():
    N = int(input())
    children = list(map(int, input().split()))

    votes = [0]*(N+1)
    for i in range(N):
        d = i+1-children[i]
        if d < 0:
            d += N
        votes[1+d] += 1

    result = 1
    result_max = votes[1]
    for i in range(2, N+1):
        if result_max < votes[i]:
            result_max = votes[i]
            result = i

    print(result)

if __name__ == '__main__':
    main()
