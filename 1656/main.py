def main():
    N = int(input())
    data = [0]*(N*N)
    for i in range(N*N):
        data[i] = int(input())
    data.sort(reverse=True)

    mid = int(N/2)
    sorted_data = []
    for i in range(N):
        sorted_data.append([0]*N)
    data_pos = 0
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if abs(i-mid)+abs(j-mid)==k:
                    sorted_data[i][j] = data[data_pos]
                    data_pos += 1

    for i in range(N):
        print(' '.join(str(x) for x in sorted_data[i]))

if __name__ == '__main__':
    main()
