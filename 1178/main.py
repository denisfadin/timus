def main():
    N = int(input())
    data = list()
    for i in range(1, N+1):
        x, y = map(int, input().split())
        data.append((x, y, i))
    data.sort(key=lambda tup: tup[1])
    for i in range(0, N, 2):
        print(data[i][2], data[i+1][2])

if __name__ == '__main__':
    main()
