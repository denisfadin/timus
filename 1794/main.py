def main():
    N = int(input())
    children = list(map(lambda x: int(x)-1, input().split()))

    votes = [0]*N
    for i in range(N):
        d = i-children[i]
        votes[d + N if d < 0 else d] += 1

    result = votes.index(max(votes))
    print(result+1)

if __name__ == '__main__':
    main()
