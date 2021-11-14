def main():
    N, M = map(int, input().split())
    girls = list(map(int, input().split()))
    girls.sort()
    boys = list(map(int, input().split()))
    boys.sort()
    result = sum(girls)
    for i in range(min(N, M)):
        girls.pop()
        boys.pop()
        result = min(result, sum(girls)+(i+1)*sum(boys))
    print(result)

if __name__ == '__main__':
    main()
