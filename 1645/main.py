def main():
    n = int(input())
    data = list(map(int, input().split()))

    sorted_data = [0]*n
    for i in range(n):
        sorted_data[data[i]-1] = i+1

    result = [(0, 0)]*n

    for i in range(n):
        di = sorted_data[i]

        l = 1
        for j in range(i):
            if sorted_data[j] > di:
                l += 1
        r = n
        for j in range(i+1, n):
            if di > sorted_data[j]:
                r -= 1

        result[di-1] = (l, r)

    for r in result:
        print(r[0], r[1])

if __name__ == '__main__':
    main()
