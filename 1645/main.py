def main():
    n = int(input())
    data = list(map(int, input().split()))

    sorted_data = [0]*n
    for i in range(n):
        sorted_data[data[i]-1] = i+1

    for i in range(n):
        di = sorted_data[i]

        l = 0
        for j in range(i):
            if sorted_data[j] < di:
                l += 1

        r = 0
        for j in range(i+1, n):
            if di < sorted_data[j]:
                r += 1

        print(di-l, di+r)

if __name__ == '__main__':
    main()
